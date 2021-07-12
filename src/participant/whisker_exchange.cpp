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
	m_tap.emplace(TapDevice());

	if (!m_tap->is_ok()) {
		CND_DAEMON_CRITICAL(
		  fmt::format("Failed to create tap device: {}", strerror(errno)));
		return -1;
	}

    CND_DAEMON_INFO("Listening for packets....");
	while (true) {
	    CND_DAEMON_TRACE("frame:");
        auto buf = m_tap->read_incomming_data();

        if (buf == nullptr) {
            // there mustve been an error reading from the
            // tap interface. It's already logged, so we
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
