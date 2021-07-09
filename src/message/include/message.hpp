#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <chrono>
#include <base.pb.h>
#include <sodium.h>
#include <vector>

/// Converts the message protobuf to a vector<unsigned char>. May
/// resize the into field.
bool
serialize_message_to_vector(base::Message*,
							std::vector<unsigned char>*);

/// Converts a vector<unsigned char> to a message protobuf.
bool
deserialize_vector_to_message(base::Message& into,
							  std::vector<unsigned char>& from);

/// Convert a cstr to a vector
/// \param[in] from what to convert
/// \param[out] into what to convert into
void
mutate_cstr_to_vector(unsigned char& from, std::vector<unsigned char>& into);

/// Create a test message.
base::Message
create_test_message();

/// Create a public key exchage message
base::Message
create_pk_exchange_message(unsigned char pk[crypto_box_PUBLICKEYBYTES]);

/// Get a command uid from the time. DO NOT USE AS A NONCE.
uint64_t
get_command_uid();

#endif /* MESSAGE_HPP */
