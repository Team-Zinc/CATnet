/*
 * Cross-platform compatibility superclass for sockets
 *
 * Copyright (C) 2019 Simon D. Levy
 * Modified by: Milo Banks
 *
 * MIT License
 */

#ifndef SOCKET_COMPAT_HPP
#define SOCKET_COMPAT_HPP

// Windows
#ifdef _WIN32
#pragma comment(lib, "ws2_32.lib")
#define WIN32_LEAN_AND_MEAN
#undef TEXT
#include <winsock2.h>
#include <ws2tcpip.h>

// Unix
#else
#define sprintf_s sprintf
typedef int SOCKET;
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
static const int INVALID_SOCKET = -1;
static const int SOCKET_ERROR = -1;
#endif

#include <stdio.h>

class Socket
{
  protected:
	SOCKET _sock;
	char _message[200];

	bool initWinsock(void);
	void cleanup(void);
	void inetPton(const char* host, struct sockaddr_in& saddr_in);
	void setUdpTimeout(uint32_t msec);

  public:
	void closeConnection(void);
	char* getMessage(void);
};

#endif /* SOCKET_COMPAT_HPP */
