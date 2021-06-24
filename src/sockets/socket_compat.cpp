#include <socket_compat.hpp>

bool Socket::initWinsock(void) {
#ifdef _WIN32
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        sprintf_s(_message, "WSAStartup() failed with error: %d\n", iResult);
        return false;
    }
#endif
    return true;
}


void Socket::cleanup(void) {
#ifdef _WIN32
    WSACleanup();
#endif
}


void Socket::inetPton(const char* host, struct sockaddr_in& saddr_in) {
#ifdef _WIN32
    WCHAR wsz[64];
    swprintf_s(wsz, L"%S", host);
    InetPton(AF_INET, wsz,   &(saddr_in.sin_addr.s_addr));
#else
    inet_pton(AF_INET, host, &(saddr_in.sin_addr));
#endif
}


void Socket::setUdpTimeout(uint32_t msec) {
#ifdef _WIN32
    setsockopt(_sock, SOL_SOCKET, SO_RCVTIMEO, (char*) &msec, sizeof(msec));
#else
    struct timeval timeout;
    timeout.tv_sec = msec / 1000;
    timeout.tv_usec = (msec * 1000) % 1000000;
    setsockopt(_sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
#endif
}


void Socket::closeConnection(void) {
#ifdef _WIN32
    shutdown(_sock, SD_BOTH);
    closesocket(_sock);
#else
    shutdown(_sock, SHUT_RDWR);
    close(_sock);
#endif
}

char* Socket::getMessage(void) {
    return _message;
}

