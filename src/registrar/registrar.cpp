#include "registrar.hpp"
#include <message.hpp>
#include <tcp_socket.hpp>
#include <tcp_server_socket.hpp>
#include <thread>

#include <message.hpp>
#include <encrypt.hpp>
#include <log.hpp>
#include <vector>
#include <head_whisker_exchange.pb.h>

Registrar::Registrar()
{
	CND_REGISTRAR_TRACE("Constructing registrar....");

	// NOTICE: threads will be implemented when it is neccicary for the
	// registrar to do multiple things at once. Currently, all the registrar
	// needs to do is connect to a wasker and inform it that it has connected

	// this section will also deal with storing participant info with JSON in
	// the future
}

void
Registrar::tcp_init()
{
	CND_REGISTRAR_TRACE("Creating tcp server socket for registrar...");
	s_head.emplace("localhost", 44400);
}

void
Registrar::run()
{
	CND_REGISTRAR_TRACE("Running in registrar mode....");
	if (!s_head.has_value()) {
		tcp_init();
	}

	CND_REGISTRAR_TRACE("Listening for connections from participants...");
	while (true) {
		s_head->acceptConnection();
		if (s_head->isConnected()) {
			CND_REGISTRAR_TRACE("Connected to a participant!");

			// Call offshoot function
            CND_REGISTRAR_TRACE("Sending test message to confirm connection with participant...");
            confirm_connection();
		}
	}
}
void Registrar::confirm_connection()
{
    std::vector<unsigned char> serialized_message;
    head_whisker_exchange::Message test = create_test_message();
    CND_REGISTRAR_TRACE("Serializing test message");
    if (! serialize_message_to_vector(&test, &serialized_message))
    {
        CND_REGISTRAR_TRACE("Test message serialization failed.");
        return;
    }
    if (!s_head->sendData(&serialized_message)) {
        CND_REGISTRAR_TRACE("Message was sucessfully serialized, but failed to send");
        return;

        //TODO: make it so that this function runs in response to a test message from RegistrarExchange::test_connection()
    }
}

Registrar::~Registrar()
{
	CND_REGISTRAR_TRACE("Destructing registrar....");
}
