#include <iostream>
#include <fstream>
#include <string>

#include "registrar_exchange.hpp"

#include <head_whisker_exchange.pb.h>
#include <log.hpp>
#include <vector>
#include <sodium.h>

#include <message.hpp>

using namespace head_whisker_exchange;

void RegistrarExchange::init() {
    CND_PARTICIPANT_RE_DEBUG("Constructing RegistrarExchange....");

    s_Client.emplace("localhost", 30003);
}

/// \brief Creates a test message, with an ID of one.
Message create_test_message() {
    Message test_message;
    test_message.set_command(Message_Command::Message_Command_TEST_CONNECTION); // Testing command
    test_message.set_id(get_command_uid());

    return test_message;
}

void RegistrarExchange::run() {
    init(); // TODO: Figure out how to run this before thread start

    // Establish connection
    CND_PARTICIPANT_RE_INFO("Establishing connection to registrar....");
    s_Client->openConnection();
    if (! s_Client->isConnected()) {
        CND_PARTICIPANT_RE_CRITICAL("Failed to open connection to registrar. Is it running?");
        return;
    }

    // Create test message
    CND_PARTICIPANT_RE_DEBUG("Creating test message....");
    Message message = create_test_message();

    // Convert test message
    CND_PARTICIPANT_RE_DEBUG("Serializing test message....");
    std::vector<unsigned char> vec_message;
    if (! serialize_message_to_vector(&message, &vec_message)) {
        CND_PARTICIPANT_RE_CRITICAL("Failed to serialize head_whisker_exchange::Message to send over the network.");
        return;
    }

    // Send test message
    CND_PARTICIPANT_RE_INFO("Testing connection....");
    if (! s_Client->sendData(&vec_message)) {
        CND_PARTICIPANT_RE_CRITICAL("Failed to send serialized message.");
        return;
    }

    std::vector<unsigned char> recieved_vec{};
    if (! s_Client->receiveData(&recieved_vec)) {
        CND_PARTICIPANT_RE_CRITICAL("Failed to recieve message sent by registrar (directly after test message.)");
        return;
    }

    Message recieved;
    deserialize_vector_to_message(recieved, recieved_vec);

    if (recieved.response().size() != 0) {
        CND_PARTICIPANT_RE_CRITICAL("The registrar you are trying to connect refused connect, or one couldn't be established in the first place: ");
        for (auto line : recieved.response()) {
            CND_PARTICIPANT_RE_CRITICAL(line);
        }
    }

    // Encrypt with libSodium
    CND_PARTICIPANT_RE_INFO("Encrypting....");
    CND_PARTICIPANT_RE_DEBUG("Asking for registrar's public key....");
    CND_PARTICIPANT_RE_DEBUG("Sending registrar our public key....");


    // Share public key, registrar checks it and returns value. Bail if rejected
    CND_PARTICIPANT_RE_INFO("Authenticating....");
    CND_PARTICIPANT_RE_WARN("Not implemented!");

    // Share ip, hostname, pub key
    CND_PARTICIPANT_RE_INFO("Sharing additive group contact information....");
    CND_PARTICIPANT_RE_WARN("Not implemented!");

    // Recieve everyones ip, hostname, pub key
    CND_PARTICIPANT_RE_INFO("Receiving group contact information....");
    CND_PARTICIPANT_RE_WARN("Not implemented!");
}

void RegistrarExchange::destroy() {
    s_Client->closeConnection();
}

