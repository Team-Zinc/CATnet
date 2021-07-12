// https://backreference.org/2010/03/26/taptap-interface-tutorial/

#include "include/tap.hpp"
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

TapDevice::TapDevice()
{
    CND_DAEMON_DEBUG("Allocating tap device....");
	if (tap_alloc(&m_tap) != 0) {
        CND_DAEMON_CRITICAL(fmt::format("Failed to create tap device: {}", strerror(errno)));
        exit(EXIT_FAILURE);
    }

    CND_DAEMON_DEBUG("Bringing tap device up....");
    if (bring_tap_up(&m_tap) != 0) {
        CND_DAEMON_CRITICAL(fmt::format("Failed to bring tap device up: {}", strerror(errno)));
        exit(EXIT_FAILURE);
    }

    /* CND_DAEMON_DEBUG("Assigning tap device IPv4 ip....");
    if (assign_tap_ipv4(&tap) != 0) {
        CND_DAEMON_CRITICAL(fmt::format("Failed to assign IP to tap device: {}", strerror(errno)));
        exit(EXIT_FAILURE);
    } */
}

TapDevice::~TapDevice() {}

bool
TapDevice::is_ok()
{
	return this->m_device >= 0;
}

std::vector<char>* TapDevice::read_incomming_data() {
    static std::vector<char> buf(1500);

    CND_DAEMON_TRACE("reading....");
    if (read(m_device, buf.data(), buf.size())) {
        CND_DAEMON_ERROR(fmt::format("Failed to read from tap interface: {}", strerror(errno)));

        return nullptr;
    }
    CND_DAEMON_TRACE("read!");

    return &buf;
}
