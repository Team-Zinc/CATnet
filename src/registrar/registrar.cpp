#include "registrar.hpp"
#include <tcp_socket.hpp>
#include <tcp_server_socket.hpp>
#include <thread>
#include <message.hpp>

#include "../logging/include/log.hpp"


Registrar::Registrar() {
    CND_REGISTRAR_TRACE("Constructing registrar....");

    // NOTICE: threads will be implemented when it is neccicary for the registrar to do multiple things at once. 
    // Currently, all the registrar needs to do is connect to a wasker and inform it that it has connected

    // this section will also deal with storing participant info with JSON in the future


}

void Registrar::tcp_init()
{
    CND_REGISTRAR_TRACE("Creating tcp server socket for registrar...");
    head.emplace("localhost", 44400);
}


void Registrar::run() {
    CND_REGISTRAR_TRACE("Running in registrar mode....");
    if (! head.has_value())
    {
        tcp_init();
    }

    CND_REGISTRAR_TRACE("Listening for connections from participants...");
    bool connected = false;
    int attempts = 0;
    while (! connected)
    {
        head->acceptConnection();
        if (head->isConnected())
        {
            CND_REGISTRAR_TRACE("Connected to a participant!");
            connected = true;
        }
        else
        {
            CND_REGISTRAR_TRACE("No connection found, trying again...");
            // TODO: make it wait a couple seconds before trying again
            attempts++;
            if (attempts == 10)
            {
                CND_REGISTRAR_TRACE("Connection timed out.");
                break;
            }
        }
    }
    CND_REGISTRAR_TRACE("Sending test message to confirm connection with participant...");
    confirm_connection();

}
void Registrar::confirm_connection()
{
    std::vector<unsigned char> serialized_message;
    Message test = create_test_message();
    CND_REGISTRAR_TRACE("Serializing test message");
    if (! serialize_message_to_vector(&test, &serialized_message))
    {
        CND_REGISTRAR_TRACE("Test message serialization failed.")
        return;
    }
    if (!head->sendData(&serialized_message)) {
        CND_REGISTRAR_TRACE("Message was sucessfully serialized, but failed to send")
        return;

        //TODO: make it so that this function runs in response to a test message from RegistrarExchange::test_connection()
    }


}


Registrar::~Registrar() {
    CND_REGISTRAR_TRACE("Destructing registrar....");
}
