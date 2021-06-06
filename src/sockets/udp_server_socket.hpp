/*
 * Class for UDP server sockets
 *
 * Copyright (C) 2019 Simon D. Levy
 *
 * MIT License
 */

#pragma once

#include "udp_socket.hpp"

class UdpServerSocket : public UdpSocket {
    public:
        UdpServerSocket(const short port, const uint32_t timeoutMsec);
};
