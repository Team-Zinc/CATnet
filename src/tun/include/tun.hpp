#ifndef TUN_HPP
#define TUN_HPP

extern "C" {
#include "alloc.h"
}

#include <vector>
#include <exception>
#include <fmt/core.h>
#include <string>
#include <errno.h>

class TunDevice
{
  public:
	int init();
	void destroy();

	bool is_ok();
    std::vector<char>* read_incomming_data();
  private:
    AllocatedTun m_tun;
};

#endif /* TUNH_HPP */
