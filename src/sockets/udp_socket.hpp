/*
 * Class for UDP sockets
 *
 * Copyright (C) 2019 Simon D. Levy
 *
 * MIT License
 */

#ifndef UDP_SOCKET_HPP
#define UDP_SOCKET_HPP

#include "socket_compat.hpp"

class UdpSocket : public Socket {
    protected:
        struct sockaddr_in _si_other;
        socklen_t _slen = sizeof(_si_other);

        void setupTimeout(uint32_t msec);

    public:
        void sendData(void * buf, size_t len);
        bool receiveData(void * buf, size_t len);
};

#endif /* UDP_SOCKET_HPP */

