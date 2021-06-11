#include <iostream>
#include <fstream>
#include <string>

#include "registrar_exchange.hpp"

#include <head_whisker_exchange.pb.h>
#include <log.hpp>

#include "message.hpp"

using namespace head_whisker_exchange;

void RegistrarExchange::init() {
    CND_INFO("Constructing RegistrarExchange....");

    s_Client.emplace("localhost", 30003);
}

void RegistrarExchange::run() {
    init(); // TODO: Figure out how to run this before thread start

    // Establish connection
    CND_INFO("Establishing connection to registrar....");
    s_Client->openConnection();
    if (! s_Client->isConnected()) {
        CND_CRITICAL("Failed to open connection to registrar. Is it running?");
        return;
    }

    // Create test message
    CND_TRACE("Creating test message....");
    Message message;
    message.set_command(Message_Command::Message_Command_TEST_CONNECTION); // Testing command
    message.set_id(1); // Not strictly nessisary

    // Convert test message
    CND_TRACE("Serializing test message....");
    std::vector<unsigned char> vec_message;
    if (! serialize_message_to_vector(&message, &vec_message)) {
        CND_CRITICAL("Failed to serialize head_whisker_exchange::Message to send over the network.");
        return;
    }

    // Send test message
    CND_INFO("Sending test message....");
    if (! s_Client->sendData(&vec_message)) {
        CND_CRITICAL("Failed to send serialized message.");
        return;
    }

    // Share public key, registrar checks it and returns value. Bail if rejected
    CND_INFO("Authenticating....");
    CND_WARN("Not implemented!");

    // Encrypt with libSodium
    CND_INFO("Encrypting....");
    CND_WARN("Not implemented!");

    // Share ip, hostname, pub key
    CND_INFO("Sharing additive group contact information....");
    CND_WARN("Not implemented!");

    // Recieve everyones ip, hostname, pub key
    CND_INFO("Receiving group contact information....");
    CND_WARN("Not implemented!");
}

void RegistrarExchange::destroy() {
    s_Client->closeConnection();
}

