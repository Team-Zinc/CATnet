#include "registrar.hpp"
#include <tcp_socket.hpp>
#include <tcp_server_socket.hpp>
#include <thread>
#include "../message/include/message.hpp"
#include "../message/include/encrypt.hpp"
#include "../logging/include/log.hpp"
#include <vector>
#include <head_whisker_exchange.pb.h>


Registrar::Registrar() {
    CND_REGISTRAR_TRACE("Constructing registrar....");

    // NOTICE: threads will be implemented when it is neccicary for the registrar to do multiple things at once. 
    // Currently, all the registrar needs to do is connect to a wasker and inform it that it has connected

    // this section will also deal with storing participant info with JSON in the future
    tcp_init();

}

void Registrar::tcp_init()
{
    CND_REGISTRAR_TRACE("Creating tcp server socket for registrar...");
    head.emplace("localhost", 44400);
}


void Registrar::run() {
    CND_REGISTRAR_TRACE("Running in registrar mode....");

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
    CND_REGISTRAR_TRACE("Testing connection with participant...");
    confirm_connection();
}
void Registrar::confirm_connection()
{
    
    std::vector<unsigned char> recieved_message{};
    

    if (!head->receiveData(&recieved_message)){
        CND_REGISTRAR_TRACE("No test message was recieved from participant.");
        return;
    }

    head_whisker_exchange::Message recieved_deserialized;
    deserialize_vector_to_message(recieved_deserialized, recieved_message);
    CND_REGISTRAR_TRACE("Test message recieved, replying...");
    //TODO: find somewhere to dump/desplay the newly deserialized test message from the participant

    std::vector<unsigned char> serialized_message;
    head_whisker_exchange::Message test = create_test_message();
    CND_REGISTRAR_TRACE("Serializing test message");
    if (! serialize_message_to_vector(&test, &serialized_message))
    {
        CND_REGISTRAR_TRACE("Test message serialization failed.");
        return;
    }

    if (!head->sendData(&serialized_message)) {
        CND_REGISTRAR_TRACE("Message was sucessfully serialized, but failed to send");
        return;
    }
    else {
        CND_REGISTRAR_TRACE("Message sent!");
    }


}


Registrar::~Registrar() {
    CND_REGISTRAR_TRACE("Destructing registrar....");
}
