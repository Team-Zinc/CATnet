#include "participant.hpp"

#include <log.hpp>

#include "whisker_exchange.hpp"
#include "registrar_exchange.hpp"

Participant::Participant() {
    m_RegistrarExchangeThread = std::thread(&RegistrarExchange::run); // Participant Registrar exchange thread
    m_WhiskerExchangeThread = std::thread(&WhiskerExchange::run); // Participant Whisker exchange thread

    // Constructors (for right now) should be run inside the run methods.
    // RegistrarExchange::init();
    // WhiskerExchange::init();
}

void Participant::run() {
    // We need to start a thread to communicate with the registrar,
    // and to forward/send/receive packets from other whiskers.

    CND_PARTICIPANT_RE_DEBUG("Starting registrar and whisker communication based exchange threads....");
    m_RegistrarExchangeThread.join();
    m_WhiskerExchangeThread.join();
}

Participant::~Participant() {
    RegistrarExchange::destroy();
    WhiskerExchange::destroy();
}

