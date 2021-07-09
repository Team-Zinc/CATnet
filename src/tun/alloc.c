#include "include/alloc.h"

#include <linux/if.h>
#include <linux/if_tun.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/// Allocates a tun device. The kernel picks the name
/// of the device.
/// https://www.kernel.org/doc/Documentation/networking/tuntap.txt
/// I love linux documentation. Seriously. I do.
/// TODO: Support multiqueue (paralell tun)
int
tun_alloc()
{
#ifdef __linux__
    struct ifreq ifr;
    int fd, err;
    char dev[] = "\0"; // Let the kernel pick a name

    if ((fd = open(TUN_CLONE_DEVICE, O_RDWR)) < 0) {
        return fd;
    }

    memset(&ifr, 0, sizeof(ifr));

    ifr.ifr_flags = IFF_TUN; 
    if (*dev) {
        strncpy(ifr.ifr_name, dev, IFNAMSIZ);
    }

    if ((err = ioctl(fd, TUNSETIFF, (void *) &ifr)) < 0) {
        close(fd);
        return err;
    }

    strcpy(dev, ifr.ifr_name);
    return fd;
#else
#error I know MacOS is techinically supported, but I do not have access to a MacOS testing machine right now. As such, the TUN wrapper doesn't work. Expect this to be fixed in less than a week.
#endif
}   
