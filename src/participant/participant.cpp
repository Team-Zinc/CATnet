#include "participant.hpp"

#include "../logging/include/log.hpp"

Participant::Participant() {
    CND_TRACE("Constructing participant....");
}

void Participant::run() {
    CND_TRACE("Running in participant mode....");
}

Participant::~Participant() {
    CND_TRACE("Destructing participant....");
}

