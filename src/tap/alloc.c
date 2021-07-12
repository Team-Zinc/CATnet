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

/// Allocates a tap device. The kernel picks the name
/// of the device.
/// https://www.kernel.org/doc/Documentation/networking/taptap.txt
/// I love linux documentation. Seriously. I do.
/// TODO: Support multiqueue (paralell tap)
AllocatedTap*
tap_alloc()
{
#ifdef __linux__
    static AllocatedTap tap;
    static struct ifreq ifr;
    int fd, err;
    char dev[16] = "\0"; // Let the kernel pick a name

    if ((fd = open(TUN_CLONE_DEVICE, O_RDWR)) < 0) {
        return NULL;
    }

    memset(&ifr, 0, sizeof(ifr));

    ifr.ifr_flags = IFF_TAP | IFF_NO_PI; 
    if (*dev) {
        strncpy(ifr.ifr_name, dev, IFNAMSIZ);
    }

    if ((err = ioctl(fd, TUNSETIFF, (void *) &ifr)) < 0) {
        close(fd);
        return NULL;
    }

    strcpy(dev, ifr.ifr_name);

    tap.device = fd;
    tap.ifr = &ifr;

    return &tap;
#else
#error I know non-linux is techinically supported, but I do not have access to a MacOS testing machine right now. As such, the TUN wrapper doesn't work. Expect this to be fixed in less than a week.
#endif
} 
