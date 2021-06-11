#ifndef REGISTRAR_EXCHANGE_HPP
#define REGISTRAR_EXCHANGE_HPP

#include <vector>
#include <optional>

#include <tcp_client_socket.hpp>

class RegistrarExchange {
public:
    static void init();
    static void destroy();
    static void run();

private:
    inline static std::optional<TcpClientSocket> s_Client;
};

#endif 
