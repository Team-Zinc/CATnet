#include <tcp_socket.hpp>

#include <vector>

#include <log.hpp>

/// Creates a TCP socket.
TcpSocket::TcpSocket(const char* host, const short port)
{
	sprintf_s(_host, "%s", host);
	sprintf_s(_port, "%d", port);

	// No connection yet
	_sock = INVALID_SOCKET;
	_connected = false;
	*_message = 0;

	// Initialize Winsock, returning on failure
	if (!initWinsock()) {
		return;
	};

		// Set up client address info
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
	struct addrinfo hints = { 0 };
#pragma GCC diagnostic pop
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	// Resolve the server address and port, returning on failure
	_addressInfo = NULL;
	int iResult = getaddrinfo(_host, _port, &hints, &_addressInfo);
	if (iResult != 0) {
		sprintf_s(_message, "getaddrinfo() failed with error: %d", iResult);
		cleanup();
		return;
	}

	// Create a SOCKET for connecting to server, returning on failure
	_sock = socket(_addressInfo->ai_family,
				   _addressInfo->ai_socktype,
				   _addressInfo->ai_protocol);
	if (_sock == INVALID_SOCKET) {
		sprintf_s(_message, "socket() failed");
		cleanup();
		return;
	}
}

/// \brief Send data along the current socket. Returns true if the message is
/// done.
bool
TcpSocket::sendData(std::vector<unsigned char>* buf)
{
	return (size_t)send(_conn, &(*buf)[0], buf->size(), 0) <= buf->size();
}

/// \brief Receive data from the current socket. Returns true if success.
bool
TcpSocket::receiveData(std::vector<unsigned char>* buf)
{
	return (size_t)recv(_conn, &(*buf)[0], buf->size(), 0) <= buf->size();
}

/// \brief Are we connected?
bool
TcpSocket::isConnected()
{
	return _connected;
}
