#ifndef REGISTRAR_HPP
#define REGISTRAR_HPP

#include <optional>
#include <tcp_server_socket.hpp>
#include <vector>
/// \brief Registrar class that contains all the data needed for runtime in case
/// of registrar mode.
namespace Registrar {
/// Constructor for the registrar.
/// If you need to pass in any arguments, please add them to the
/// subcommand, and pass that in here. Do not pass them in individually.
void
init();

/// \brief Destructor for the registrar.
void
destroy();

/// \brief Run the main code that actually gives the registrar purpose.
/// If you need to pass in any arguments, please add them to the
/// subcommand, and pass that in here. Do not pass them in individually.
void
run();

/// Confirms the connection with a participant by sending a test message
void
confirm_connection();

// Opens a tcp server socket for the registrar to make connections on
void
tcp_init();

inline static std::optional<TcpServerSocket> s_server;
};

#endif /* REGISTRAR_HPP */
