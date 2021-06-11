#include <udp_socket.hpp>

void UdpSocket::setupTimeout(uint32_t msec) {
    if (msec > 0) {
        Socket::setUdpTimeout(msec);
    }
}


void UdpSocket::sendData(void * buf, size_t len) {
    sendto(_sock, (const char *)buf, (int)len, 0, (struct sockaddr *) &_si_other, (int)_slen);
}

bool UdpSocket::receiveData(void * buf, size_t len) {
    return recvfrom(_sock, (char *)buf, (int)len, 0, (struct sockaddr *) &_si_other, &_slen) == _slen;
}


