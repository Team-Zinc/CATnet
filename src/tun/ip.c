#include "include/ip.h"

#include <linux/if.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <string.h>
#include <unistd.h>

int assign_tun_ipv4(AllocatedTun* tun) {
    int err;

    tun->ifr->ifr_addr.sa_family = AF_INET;
    // TODO: https://stackoverflow.com/questions/64608067/linux-socket-c-c-what-is-the-best-way-to-check-if-ip-port-is-already-in-use
    // Also, no `!= 1` is not a typo. inet_pton returns 1 on success, weirdly enough.
    if (inet_pton(AF_INET, "10.42.69.30", &((struct sockaddr_in*)&tun->ifr->ifr_addr)->sin_addr) != 1) {
        close(tun->sock);
        return -1;
    }

    if ((err = ioctl(tun->sock, SIOCSIFADDR, tun->ifr)) < 0) {
        close(tun->sock);
        return err;
    }

    if (inet_pton(AF_INET, "255.255.0.0", &((struct sockaddr_in*)&tun->ifr->ifr_addr)->sin_addr) != 1) {
        close(tun->sock);
        return -1;
    }

    if ((err = ioctl(tun->sock, SIOCSIFNETMASK, tun->ifr)) < 0) {
        close(tun->sock);
        return err;
    }

    if ((err = ioctl(tun->sock, SIOCSIFFLAGS, tun->ifr)) < 0) {
        close(tun->sock);
        return err;
    }
 
    tun->ifr->ifr_flags |= (IFF_UP | IFF_RUNNING);

    if ((err = ioctl(tun->sock, SIOCGIFFLAGS, tun->ifr)) < 0) {
        close(tun->sock);
        return err;
    }

    close(tun->sock);

    return 0;
}

