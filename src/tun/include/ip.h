#ifndef IP_H
#define IP_H

#include "alloc.h"

/// Assign a local/private IP to the allocated tun
/// device. Implementing for IPv6 should be relatively
/// straight forward. What about IPv8 you ask? I'm pretty
/// sure only 37 people use it, and we don't care about
/// them.
int assign_tun_ipv4(AllocatedTun* tun);

#endif /* IP_H */
