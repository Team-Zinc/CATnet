/*
 * Cross-platform compatibility superclass for sockets
 *
 * Copyright (C) 2019 Simon D. Levy
 *
 * MIT License
 */

#ifndef TCP_SOCKET_HPP
#define TCP_SOCKET_HPP

#include "socket_compat.hpp"

class TcpSocket : public Socket {
    protected:
        char _host[200];
        char _port[10];
        SOCKET _conn;
        struct addrinfo * _addressInfo;
        bool _connected;

        TcpSocket(const char * host, const short port);
    public:
        bool sendData(void *buf, size_t len);
        bool receiveData(void *buf, size_t len);
        bool isConnected();
};

#endif /* TCP_SOCKET_HPP */
