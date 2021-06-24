#include <udp_socket.hpp>

void
UdpSocket::setupTimeout(uint32_t msec)
{
	if (msec > 0) {
		Socket::setUdpTimeout(msec);
	}
}

void
UdpSocket::sendData(std::vector<unsigned char>* buf)
{
	sendto(_sock,
		   &(*buf)[0],
		   (int)buf->size(),
		   0,
		   (struct sockaddr*)&_si_other,
		   (int)_slen);
}

bool
UdpSocket::receiveData(std::vector<unsigned char>* buf)
{
	return recvfrom(_sock,
					&(*buf)[0],
					(int)buf->size(),
					0,
					(struct sockaddr*)&_si_other,
					&_slen) == _slen;
}
