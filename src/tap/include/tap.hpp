#ifndef TUN_HPP
#define TUN_HPP

extern "C" {
#include "alloc.h"
}

#include <vector>

class TapDevice
{
  public:
	TapDevice();
	~TapDevice();

	bool is_ok();
    std::vector<char>* read_incomming_data();
  private:
	int m_device;
    AllocatedTap m_tap;
};

#endif /* TUNH_HPP */
