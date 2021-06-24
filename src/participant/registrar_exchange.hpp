#ifndef REGISTRAR_EXCHANGE_HPP
#define REGISTRAR_EXCHANGE_HPP

#include <optional>
#include <vector>

#include <tcp_client_socket.hpp>

class RegistrarExchange
{
  public:
	static void init();
	static void destroy();
	static void run();

	static void test_connection();
    static void encrypt_session();
  private:
	inline static std::optional<TcpClientSocket> s_Client;
};

#endif
