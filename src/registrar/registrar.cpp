#include "registrar.hpp"
#include <message.hpp>
#include <tcp_socket.hpp>
#include <tcpserver_socket.hpp>
#include <thread>

#include "../logging/include/log.hpp"

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
	head.emplace("localhost", 44400);
}

void
Registrar::run()
{
	CND_REGISTRAR_TRACE("Running in registrar mode....");
	if (!head.has_value()) {
		tcp_init();
	}

	CND_REGISTRAR_TRACE("Listening for connections from participants...");
	bool connected = false;
	while (!connected) {
		head->acceptConnection();
		if (head->isConnected) {
			CND_REGISTRAR_TRACE("Connected to a participant!");
			connected = true;
		} else {
			CND_REGISTRAR_TRACE("No connection found, trying again...");
		}
	}
}

Registrar::~Registrar()
{
	CND_REGISTRAR_TRACE("Destructing registrar....");
}
