#include "message.hpp"
#include "head_whisker_exchange.pb.h"

#include <log.hpp>

/// \brief Converts the message protobuf to a vector<unsigned char>. May
///         resize the into field.
bool serialize_message_to_vector(head_whisker_exchange::Message* message, std::vector<unsigned char>* into) {
    size_t byte_size = message->ByteSizeLong();

    if (into->size() < byte_size) {
        into->resize(byte_size / sizeof(unsigned char));
    }

    // https://github.com/protocolbuffers/protobuf/issues/5431
    return message->SerializeToArray(into->data(), byte_size);
}

/// \brief Converts a vector<unsigned char> to a message protobuf.
bool deserialize_vector_to_message(head_whisker_exchange::Message& into, std::vector<unsigned char>& from) {
    return into.ParseFromArray(from.data(), from.size());
}

/// \brief Gets a unique identifier for a command
uint64_t get_command_uid() {
    static uint64_t current = 0;

    if (current == 0 ) {
        auto now = std::chrono::system_clock::now();
        auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
        auto epoch = now_ms.time_since_epoch();
        auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);

        current = value.count();
    }

    return current;
}
