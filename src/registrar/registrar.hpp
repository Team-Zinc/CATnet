#ifndef REGISTRAR_HPP
#define REDISTRAR_HPP

#include <vector>
#include <optional>
#include <tcp_server_socket.hpp>
/// \brief Registrar class that contains all the data needed for runtime in case of registrar mode.
class Registrar {
public:
    /// \brief Constructor for the registrar.
    /// If you need to pass in any arguments, please add them to the
    /// subcommand, and pass that in here. Do not pass them in individually.
    Registrar();

    /// \brief Destructor for the registrar.
    ~Registrar();
    
    /// \brief Run the main code that actually gives the registrar purpose.
    /// If you need to pass in any arguments, please add them to the
    /// subcommand, and pass that in here. Do not pass them in individually.
    void run();

    // Opens a tcp server socket for the registrar to make connections on
    void tcp_init();

    private:
        inline static std::optional<TcpServerSocket> head;

    

};

