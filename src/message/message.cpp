#include "include/message.hpp"
#include "base.pb.h"

#include <log.hpp>

bool
serialize_message_to_vector(base::Message* message,
							std::vector<unsigned char>* into)
{
	size_t byte_size = message->ByteSizeLong();

	if (into->size() < byte_size) {
		into->resize(byte_size / sizeof(unsigned char));
	}

	// https://github.com/protocolbuffers/protobuf/issues/5431
	return message->SerializeToArray(into->data(), byte_size);
}

bool
deserialize_vector_to_message(base::Message& into,
							  std::vector<unsigned char>& from)
{
	return into.ParseFromArray(from.data(), from.size());
}

void
mutate_cstr_to_vector(unsigned char& from, std::vector<unsigned char>& into)
{
	into = std::vector<unsigned char>(
	  from, from + (sizeof(from) * sizeof(unsigned char)));
}

uint64_t
get_command_uid()
{
	static uint64_t current = 0;

	if (current == 0) {
		auto now = std::chrono::system_clock::now();
		auto now_ms =
		  std::chrono::time_point_cast<std::chrono::milliseconds>(now);
		auto epoch = now_ms.time_since_epoch();
		auto value =
		  std::chrono::duration_cast<std::chrono::milliseconds>(epoch);

		current = value.count();
	}

	return current;
}

base::Message
create_test_message()
{
	base::Message test_message;

	test_message.mutable_test_connection(); // Set as the testing commandw
	test_message.set_id(get_command_uid());

	return test_message;
}

base::Message
create_pk_exchange_message(unsigned char pk[crypto_box_PUBLICKEYBYTES])
{
	base::Message exchange_message;

	auto sub = exchange_message.mutable_pubkey_exchange();
	sub->set_pubkey(reinterpret_cast<char*>(pk));
	exchange_message.set_id(get_command_uid());

	return exchange_message;
}
