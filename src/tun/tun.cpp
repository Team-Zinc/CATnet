// https://backreference.org/2010/03/26/tuntun-interface-tutorial/

#include "include/tun.hpp"
#include <linux/if.h>
extern "C"
{
#include "include/alloc.h"
#include "include/up.h"
#include "include/ip.h"
}

#include <errno.h>
#include <string>

#include <log.hpp>
#include <fmt/core.h>

int TunDevice::init()
{
    CND_DAEMON_DEBUG("Allocating tun device....");
	if (tun_alloc(&m_tun) != 0) {
        CND_DAEMON_CRITICAL(fmt::format("Failed to allocate tun device: {}", strerror(errno)));
        m_tun.device = 0;

        return -1;
    }

    CND_DAEMON_DEBUG("Bringing tun device up....");
    if (bring_tun_up(&m_tun) != 0) {
        CND_DAEMON_CRITICAL(fmt::format("Failed to bring tun device up: {}", strerror(errno)));
        m_tun.device = 0;

        return -1;
    }

    CND_DAEMON_DEBUG("Assigning tun device IPv4 ip....");
    if (assign_tun_ipv4(&m_tun) != 0) {
        CND_DAEMON_CRITICAL(fmt::format("Failed to assign IP to tun device: {}", strerror(errno)));
        m_tun.device = 0;

        return -1;
    }

    return 0;
}

void TunDevice::destroy() {
    tun_dealloc(&m_tun);
}

bool
TunDevice::is_ok()
{
	return this->m_tun.device >= 0;
}

std::vector<char>* TunDevice::read_incomming_data() {
    static std::vector<char> buf;
    buf.reserve(1800);

    usleep(1000);

    if (read(this->m_tun.device, buf.data(), buf.size())) {
        CND_DAEMON_ERROR(fmt::format("Failed to read from tun interface: {}", strerror(errno)));

        return nullptr;
    }

    return &buf;
}
