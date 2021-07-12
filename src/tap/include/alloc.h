#ifndef ALLOC_H
#define ALLOC_H

#define TUN_CLONE_DEVICE "/dev/net/tun"

/// Basically a wrapper around a device and
/// the kernel chosen name for a TUN device.
typedef struct {
    int device;
    struct ifreq* ifr;
} AllocatedTap;

int tap_alloc(AllocatedTap* tap);

#endif /* ALLOC_H */
