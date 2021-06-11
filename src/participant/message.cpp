#include "message.hpp"
#include "head_whisker_exchange.pb.h"

#include <log.hpp>

/// \briref Converts the message protobuf to a vector<unsigned char>. May
///         resize the into field.
bool serialize_message_to_vector(head_whisker_exchange::Message* message, std::vector<unsigned char>* into) {
    size_t byte_size = message->ByteSizeLong();

    if (into->size() < byte_size) {
        into->resize(byte_size / sizeof(unsigned char));
    }

    // https://github.com/protocolbuffers/protobuf/issues/5431
    return message->SerializeToArray(into->data(), byte_size);
}
