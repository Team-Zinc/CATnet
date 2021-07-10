#include <fstream>
#include <iostream>
#include <string>

#include <update_catstate.hpp>

#include <base.pb.h>
#include <log.hpp>
#include <sodium.h>
#include <vector>

#include "../message/include/encrypt.hpp" // TODO: Use arrow notation, YouCompleteMe is screaming at me for now
#include "../message/include/message.hpp" // TODO: Use arrow notation, YouCompleteMe is screaming at me for now

using namespace base;

void
RegistrarExchange::init()
{
	s_Client.emplace("localhost", 30003);
}

void
RegistrarExchange::test_connection()
{
	std::vector<unsigned char> vec_message;

	// Create test message
	CND_DAEMON_DEBUG("Creating test message....");
	Message message = create_test_message();

	// Convert test message
	CND_DAEMON_DEBUG("Serializing test message....");
	if (!serialize_message_to_vector(&message, &vec_message)) {
		CND_DAEMON_CRITICAL(
		  "Failed to serialize base::Message to send over the "
		  "network.");
		return;
	}

	// Send test message
	CND_DAEMON_DEBUG("Sending test message....");
	if (!s_Client->sendData(&vec_message)) {
		CND_DAEMON_CRITICAL("Failed to send serialized message.");
		return;
	}

	CND_DAEMON_DEBUG("Waiting for message to be sent back....");
	std::vector<unsigned char> recieved_vec{};
	if (!s_Client->receiveData(&recieved_vec)) {
		CND_DAEMON_CRITICAL(
		  "Failed to recieve message sent by registrar (directly after test "
		  "message.)");
		return;
	}

	Message recieved;
	deserialize_vector_to_message(recieved, recieved_vec);

	if (recieved.response().size() != 0) {
		CND_DAEMON_CRITICAL(
		  "The registrar you are trying to connect refused connect, or one "
		  "couldn't be established in the first place: ");
		for (auto line : recieved.response()) {
			CND_DAEMON_CRITICAL(line);
		}
	}
}

void
RegistrarExchange::encrypt_session()
{
	std::vector<unsigned char> vec_message;
	SessionEncryptionState enc_state;
	Message pk_exchange_message =
	  create_pk_exchange_message(enc_state.get_our_pk());

	CND_DAEMON_DEBUG("Serializing key exchange message....");
	if (!serialize_message_to_vector(&pk_exchange_message, &vec_message)) {
		CND_DAEMON_CRITICAL(
		  "Failed to serialize base::Message to send over the "
		  "network for key exchange.");
		return;
	}

	CND_DAEMON_DEBUG("Waiting for registrar's public key....");
	if (!s_Client->sendData(&vec_message)) {
		CND_DAEMON_CRITICAL(
		  "Failed to send serialized message for key exchange.");
		return;
	}
}

int
RegistrarExchange::update_catstate()
{
	init(); // TODO: Figure out how to run this before thread start

	// Establish connection
	CND_DAEMON_INFO("Establishing connection to registrar....");
	s_Client->openConnection();
	if (!s_Client->isConnected()) {
		CND_DAEMON_CRITICAL(
		  "Failed to open connection to registrar. Is it running?");
		return -1;
	}

	CND_DAEMON_INFO("Verifying connection and protobuf integrety....");
	test_connection();

	CND_DAEMON_INFO("Exchanging public keys with registrar....");
	encrypt_session();

	// Share public key, registrar checks it and returns value. Bail if rejected
	CND_DAEMON_INFO("Authenticating....");
	CND_DAEMON_WARN("Not implemented!");

	// Share ip, hostname, pub key
	CND_DAEMON_INFO("Sharing additive group contact information....");
	CND_DAEMON_WARN("Not implemented!");

	// Recieve everyones ip, hostname, pub key
	CND_DAEMON_INFO("Receiving group contact information....");
	CND_DAEMON_WARN("Not implemented!");

    return 0;
}

void
RegistrarExchange::destroy()
{
	s_Client->closeConnection();
}
