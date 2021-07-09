#include <whisker_exchange.hpp>

#include <iostream>

#include <log.hpp>

void
WhiskerExchange::init()
{
    CND_PARTICIPANT_PE_DEBUG("Constructing WhiskerExchange....");
}

void
WhiskerExchange::run()
{
    init(); // TODO: Figure out how to run this before thread start

    CND_PARTICIPANT_PE_INFO("Running whisker exchange....");

    CND_PARTICIPANT_PE_INFO("Creating TUN device...");
    m_tun.emplace(TunDevice());

    CND_PARTICIPANT_PE_INFO("Blocking until network state is populated....");
    while (true) {}
}

void
WhiskerExchange::destroy()
{}
