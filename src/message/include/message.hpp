#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <chrono>
#include <head_whisker_exchange.pb.h>
#include <sodium.h>
#include <vector>

bool
serialize_message_to_vector(head_whisker_exchange::Message*,
							std::vector<unsigned char>*);
bool
deserialize_vector_to_message(head_whisker_exchange::Message& into,
							  std::vector<unsigned char>& from);
void
mutate_cstr_to_vector(unsigned char& from, std::vector<unsigned char>& into);

head_whisker_exchange::Message
create_test_message();
head_whisker_exchange::Message
create_pk_exchange_message(unsigned char pk[crypto_box_PUBLICKEYBYTES]);

uint64_t
get_command_uid();

#endif /* MESSAGE_HPP */
