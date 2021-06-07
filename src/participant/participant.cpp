#include "participant.hpp"

#include "../logging/include/log.hpp"
#include "whisker_exchange.hpp"
#include "registrar_exchange.hpp"

Participant::Participant() {
    m_RegistrarExchangeThread = std::thread(RegistrarExchange::run);
    m_WhiskerExchangeThread = std::thread(WhiskerExchange::run);

    RegistrarExchange::init();
    WhiskerExchange::init();
}

void Participant::run() {
    // We need to start a thread to communicate with the registrar,
    // and to forward/send/receive packets from other whiskers.

    CND_INFO("Starting registrar and whisker communication based exchange threads....");
    m_RegistrarExchangeThread.join();
    m_WhiskerExchangeThread.join();
}

Participant::~Participant() {
    RegistrarExchange::destroy();
    WhiskerExchange::destroy();
}

