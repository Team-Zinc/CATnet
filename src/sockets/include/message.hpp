#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <vector>
#include <head_whisker_exchange.pb.h>

bool serialize_message_to_vector(head_whisker_exchange::Message*, std::vector<unsigned char>*);

#endif /* MESSAGE_HPP */

