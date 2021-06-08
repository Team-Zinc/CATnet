#include "registrar_exchange.hpp"

#include <iostream>

#include "../sockets/tcp_client_socket.hpp"
#include "../logging/include/log.hpp"

void RegistrarExchange::init() {

}

void RegistrarExchange::run() {
    CND_TRACE("Establishing connection....");
    TcpClientSocket client("localhost", 30003);
    client.openConnection();

    CND_TRACE("Sending test message:");
    char message[100] = "Got some money, got some cash;";
    client.sendData(message, strlen(message));
    CND_TRACE(message);

    // Empty out the message
    memset(message, 0, strlen(message));

    CND_TRACE("Listening for response....");
    client.receiveData(message, 100);

    CND_TRACE("Received: ");
    CND_TRACE(message);

    if (strcmp(message, "I'm rich, and now I'm sad.") != 0) {
        CND_CRITICAL("Registrar did not send back correct response. Are you sure " \
                "you are using the right version, and that the registrar is trusted?");
        return;
    }

    // TODO: Move into desctructor
    client.closeConnection();
}

void RegistrarExchange::destroy() {

}

