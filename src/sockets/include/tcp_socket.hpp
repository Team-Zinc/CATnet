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

#include <vector>

#define TCP_RECIEVE_ALL_MIN_CHUNK_SIZE 500

class TcpSocket : public Socket {
    protected:
        char _host[200];
        char _port[10];
        SOCKET _conn;
        struct addrinfo * _addressInfo;
        bool _connected;

        TcpSocket(const char* host, const short port);
    public:
        bool sendData(std::vector<unsigned char>*);
        bool receiveData(std::vector<unsigned char>*);
        // void receiveAllData(std::vector<unsigned char>*);
        bool isConnected();
};

#endif /* TCP_SOCKET_HPP */
