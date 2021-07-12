#include "include/ip.h"

#include <linux/if.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <string.h>

int assign_tun_ipv4(AllocatedTap* tun) {
    int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    int err;

    tun->ifr->ifr_addr.sa_family = AF_INET;
    // TODO: https://stackoverflow.com/questions/64608067/linux-socket-c-c-what-is-the-best-way-to-check-if-ip-port-is-already-in-use
    // Also, no `!= 1` is not a typo. inet_pton returns 1 on success, weirdly enough.
    if (inet_pton(AF_INET, "10.42.69.30", &((struct sockaddr_in*)&tun->ifr->ifr_addr)->sin_addr) != 1) {
        return -1;
    }

    if ((err = ioctl(fd, SIOCGIFFLAGS, &tun->ifr)) < 0) {
        return err;
    }
    
    tun->ifr->ifr_flags |= (IFF_UP | IFF_RUNNING);

    if ((err = ioctl(fd, SIOCSIFFLAGS, &tun->ifr)) < 0) {
        return err;
    }


    return 0;
}

