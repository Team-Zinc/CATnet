// https://backreference.org/2010/03/26/tuntap-interface-tutorial/

#include "include/tun.hpp"
extern "C" {
#include "include/alloc.h"
}

TunDevice::TunDevice() {
    m_device = tun_alloc();
}

TunDevice::~TunDevice() {

}

