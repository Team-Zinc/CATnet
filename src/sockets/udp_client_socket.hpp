/*
 * Class for UDP client sockets
 *
 * Copyright (C) 2019 Simon D. Levy
 *
 * MIT License
 */

#ifndef UDP_CLIENT_SOCKET_HPP
#define UDP_CLIENT_SOCKET_HPP

#include "udp_socket.hpp"

#include <string.h>
#include <time.h>

class UdpClientSocket : public UdpSocket {
    public:
        UdpClientSocket(const char * host, const short port, const uint32_t timeoutMsec);
};

#endif /* UDP_CLIENT_SOCKET_HPP */
