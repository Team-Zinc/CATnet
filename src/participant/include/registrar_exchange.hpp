#ifndef REGISTRAR_EXCHANGE_HPP
#define REGISTRAR_EXCHANGE_HPP

#include <optional>
#include <vector>

#include <tcp_client_socket.hpp>

/// Contains the state required to exchange with the registrar
class RegistrarExchange
{
  public:
	/// Construct the #RegistrarExchange
	static void init();
	/// Destruct the #RegistrarExchange
	static void destroy();
	/// Run the code that exchanges communications with the registrar.
	static void run();

  private:
	/// Test the connection to the regisrar. Sends a test message
	/// and listens to a repsonse.
	static void test_connection();
	/// Encrypt the connection. Exchanges public keys, and goes from
	/// there.
	static void encrypt_session();

	/// TCP Socket for communication with the registrar.
	inline static std::optional<TcpClientSocket> s_Client;
};

#endif
