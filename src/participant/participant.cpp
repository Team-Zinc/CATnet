#include "include/participant.hpp"

#include <log.hpp>

#include "include/update_catstate.hpp"
#include "include/whisker_exchange.hpp"

void
Participant::init()
{
	RegistrarExchange::init();
	WhiskerExchange::init();
}

void
Participant::run()
{
	// We need to start a thread to communicate with the registrar,
	// and to forward/send/receive packets from other whiskers.

	CND_DAEMON_DEBUG("Updating catstate....");
	if (RegistrarExchange::update_catstate() != 0) {
        return;
    }

	CND_DAEMON_DEBUG("Startinig whisker exchange");
	if (WhiskerExchange::run() != 0) {
        return;
    }
}

void
Participant::destroy()
{
	RegistrarExchange::destroy();
	WhiskerExchange::destroy();
}
