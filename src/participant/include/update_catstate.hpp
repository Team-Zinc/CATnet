#ifndef REGISTRAR_EXCHANGE_HPP
#define REGISTRAR_EXCHANGE_HPP

#include <optional>
#include <vector>

#include <tcp_client_socket.hpp>

/// Contains the state required to exchange with the registrar
namespace RegistrarExchange {
/// Construct the #RegistrarExchange
void
init();
/// Destruct the #RegistrarExchange
void
destroy();
/// Run the code that exchanges communications with the registrar.
int
update_catstate();

/// Test the connection. Even though TCP already does a handshake,
/// this is nessiary to ensure that google protobuf versions match
/// and everything in that realm is working correctly.
void
test_connection();

/// Encrypt the connection. Exchanges public keys, and goes from
/// there.
void
encrypt_session();

/// TCP Socket for communication with the registrar.
inline std::optional<TcpClientSocket> s_Client;
};

#endif
