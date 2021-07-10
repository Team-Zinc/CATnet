#include "registrar.hpp"
#include <message.hpp>
#include <tcp_server_socket.hpp>
#include <tcp_socket.hpp>
#include <thread>

#include <base.pb.h>
#include <encrypt.hpp>
#include <log.hpp>
#include <message.hpp>
#include <vector>

void
Registrar::init()
{
	CND_DAEMON_TRACE("Constructing registrar....");

	// NOTICE: threads will be implemented when it is neccicary for the
	// registrar to do multiple things at once. Currently, all the registrar
	// needs to do is connect to a wasker and inform it that it has connected

	// this section will also deal with storing participant info with JSON in
	// the future
}

void
Registrar::tcp_init()
{
	CND_DAEMON_TRACE("Creating tcp server socket for registrar...");
	s_server.emplace("localhost", 44400);
}

void
Registrar::run()
{
	CND_DAEMON_TRACE("Running in registrar mode....");
	if (!s_server.has_value()) {
		tcp_init();
	}

	CND_DAEMON_TRACE("Listening for connections from participants...");
	while (true) {
		s_server->acceptConnection();
		if (s_server->isConnected()) {
			CND_DAEMON_TRACE("Connected to a participant!");

			// Call offshoot function
			CND_DAEMON_TRACE(
			  "Sending test message to confirm connection with participant...");
			confirm_connection();
		}
	}
}
void
Registrar::confirm_connection()
{
	std::vector<unsigned char> serialized_message;
	base::Message test = create_test_message();
	CND_DAEMON_TRACE("Serializing test message");
	if (!serialize_message_to_vector(&test, &serialized_message)) {
		CND_DAEMON_TRACE("Test message serialization failed.");
		return;
	}
	if (!s_server->sendData(&serialized_message)) {
		CND_DAEMON_TRACE(
		  "Message was sucessfully serialized, but failed to send");
		return;

		// TODO: make it so that this function runs in response to a test
		// message from RegistrarExchange::test_connection()
	}
}

void
Registrar::destroy()
{
	CND_DAEMON_TRACE("Destructing registrar....");
}
