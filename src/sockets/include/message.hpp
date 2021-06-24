#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <vector>
#include <head_whisker_exchange.pb.h>
#include <chrono>

bool serialize_message_to_vector(head_whisker_exchange::Message*, std::vector<unsigned char>*);
bool deserialize_vector_to_message(head_whisker_exchange::Message& into, std::vector<unsigned char>& from); 
uint64_t get_command_uid();

#endif /* MESSAGE_HPP */

