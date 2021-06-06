/*
 * Class for UDP client sockets
 *
 * Copyright (C) 2019 Simon D. Levy
 *
 * MIT License
 */

#pragma once

#include "udp_socket.hpp"

#include <string.h>
#include <time.h>

class UdpClientSocket : public UdpSocket {
    public:
        UdpClientSocket(const char * host, const short port, const uint32_t timeoutMsec);
};
