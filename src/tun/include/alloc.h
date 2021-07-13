#ifndef ALLOC_H
#define ALLOC_H

#define TUN_CLONE_DEVICE "/dev/net/tun"

/// Basically a wrapper around a device and
/// the kernel chosen name for a TUN device.
typedef struct {
    int device, sock;
    struct ifreq* ifr;
} AllocatedTun;

int tun_alloc(AllocatedTun* tun);
void tun_dealloc(AllocatedTun* tun);

#endif /* ALLOC_H */
