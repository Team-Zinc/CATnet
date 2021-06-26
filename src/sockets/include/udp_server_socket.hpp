/*
 * Class for UDP server sockets
 *
 * Copyright (C) 2019 Simon D. Levy
 *
 * MIT License
 */

#ifndef UDP_SERVER_SOCKET_HPP
#define UDP_SERVER_SOCKET_HPP

#include "udp_socket.hpp"

class UdpServerSocket : public UdpSocket
{
  public:
	UdpServerSocket(const short port, const uint32_t timeoutMsec);
};

#endif /* UDP_SERVER_SOCKET_HPP */
