#include <up.h>

#include <sys/ioctl.h>
#include <linux/if.h>
#include <string.h>

#include <stdio.h>

int bring_tap_up(AllocatedTap* tap) {
    // struct ifreq ifr;
    int fd, err;

    // ifr.ifr_flags = tap->ifr->ifr_flags;
    // strncpy((char*) ifr.ifr_name, (char*) tap->ifr->ifr_name, IFNAMSIZ);

    fd = socket(AF_INET, SOCK_DGRAM, 0); // 0: automically chose protocol
    if (fd < 0) {
        return -1;
    }

    tap->ifr->ifr_flags |= IFF_UP;
    
    printf("%s\n", tap->ifr->ifr_name);

    if ((err = ioctl(fd, SIOCSIFFLAGS, &tap->ifr)) == -1) {
        return err;
    }

    return 0;
}
