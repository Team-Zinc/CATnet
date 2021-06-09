/*
 * Class for TCP client sockets
 *
 * Copyright (C) 2019 Simon D. Levy
 *
 * MIT License
 */

#ifndef TCP_CLIENT_SOCKET_HPP
#define TCP_CLIENT_SOCKET_HPP

#include "tcp_socket.hpp"

#ifndef _WIN32
#pragma GCC diagnostic warning "-Wunused-function"
static void closesocket(int socket) { close(socket); }
#endif


class TcpClientSocket : public TcpSocket {
    public:
        TcpClientSocket(const char * host, const short port) : TcpSocket(host, port) {};
        void openConnection(void);
};

#endif /* TCP_CLIENT_SOCKET_HPP */
