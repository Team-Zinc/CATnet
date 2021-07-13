#include <whisker_exchange.hpp>

#include <errno.h>
#include <iostream>
#include <string>

#include <fmt/core.h>
#include <log.hpp>

void
WhiskerExchange::init()
{
	CND_DAEMON_DEBUG("Constructing WhiskerExchange....");
}

int
WhiskerExchange::run()
{
	init(); // TODO: Figure out how to run this before thread start

	CND_DAEMON_INFO("Running whisker exchange....");

	CND_DAEMON_INFO("Creating TUN device...");
    auto dev = TunDevice();
    if (dev.init() != 0) {
		return -1;
    }

    m_tun.emplace(dev);

    CND_DAEMON_INFO("Listening for packets....");
	while (true) {
	    CND_DAEMON_TRACE("frame:");
        auto buf = m_tun->read_incomming_data();

        if (buf == nullptr) {
            // there mustve been an error reading from the
            // tun interface. It's already logged, so we
            // can just continue
            continue;
        }

        for (auto _char : *buf) {
            CND_DAEMON_TRACE(_char);
        }
    }

    return 0;
}

void
WhiskerExchange::destroy()
{}
