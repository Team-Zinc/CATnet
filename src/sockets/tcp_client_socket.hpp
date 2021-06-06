/*
 * Class for TCP client sockets
 *
 * Copyright (C) 2019 Simon D. Levy
 *
 * MIT License
 */

#pragma once

#include "tcp_socket.hpp"

#ifndef _WIN32
static void closesocket(int socket) { close(socket); }
#endif


class TcpClientSocket : public TcpSocket {
    public:
        TcpClientSocket(const char * host, const short port) : TcpSocket(host, port) {};
        void openConnection(void);
};
