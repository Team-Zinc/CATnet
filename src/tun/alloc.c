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

/// Allocates a tun->device. The kernel picks the name
/// of the device.
/// https://www.kernel.org/doc/Documentation/networking/tun->ap.txt
/// I love linux documentation. Seriously. I do.
/// TODO: Support multiqueue (paralell tun->
int
tun_alloc(AllocatedTun* tun)
{
#ifdef __linux__
    static struct ifreq ifr;
    int fp, err;
    char dev[16] = "\0"; // Let the kernel pick a name

    if ((fp = open(TUN_CLONE_DEVICE, O_RDWR)) < 0) {
        return -1;
    }

    memset(&ifr, 0, sizeof(ifr));

    ifr.ifr_flags = IFF_TUN | IFF_NO_PI; 
    if (*dev) {
        strncpy(ifr.ifr_name, dev, IFNAMSIZ);
    }

    if ((err = ioctl(fp, TUNSETIFF, (void *) &ifr)) < 0) {
        close(fp);
        return -1;
    }

    strcpy(dev, ifr.ifr_name);

    tun->ifr = &ifr;
    tun->device = fp;

    return 0;
#else
#error I know non-linux is techinically supported, but I do not have access to a MacOS testing machine right now. As such, the TUN wrapper doesn't work. Expect this to be fixed in less than a week.
#endif
}

void tun_dealloc(AllocatedTun* tun) {
    close(tun->device);
    close(tun->sock);
}
