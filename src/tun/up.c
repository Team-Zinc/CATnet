#include <up.h>

#include <sys/ioctl.h>
#include <linux/if.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <stdio.h>

int bring_tun_up(AllocatedTun* tun) {
    // struct ifreq ifr;
    int err;

    // ifr.ifr_flags = tun->ifr->ifr_flags;
    // strncpy((char*) ifr.ifr_name, (char*) tun->ifr->ifr_name, IFNAMSIZ);

    tun->sock = socket(AF_INET, SOCK_DGRAM, 0); // 0: automically chose protocol
    if (tun->sock < 0) {
        return -1;
    }

    tun->ifr->ifr_flags = IFF_POINTOPOINT | IFF_NOARP | IFF_MULTICAST;
    if ((err = ioctl(tun->sock, SIOCGIFFLAGS, tun->ifr)) == -1) {
        close(tun->sock);
        return err;
    }

    tun->ifr->ifr_flags |= IFF_UP | IFF_RUNNING;
    if ((err = ioctl(tun->sock, SIOCSIFFLAGS, tun->ifr)) == -1) {
        close(tun->sock);
        return err;
    }

    printf("%d\n", tun->sock);

    return 0;
}
