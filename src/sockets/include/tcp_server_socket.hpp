/*
 * General-purpose socket server class
 *
 * Copyright (C) 2019 Simon D. Levy
 *
 * MIT License
 */

#ifndef TCP_SERVER_SOCKET_HPP
#define TCP_SERVER_SOCKET_HPP

#include "tcp_socket.hpp"

#ifndef _WIN32
static void
closesocket(int socket)
{
	close(socket);
}
#endif

class TcpServerSocket : public TcpSocket
{
  public:
	TcpServerSocket(const char* host, short port);
	void acceptConnection(void);
};

#endif /* TCP_SERVER_SOCKET_HPP */
