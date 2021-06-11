#include "registrar.hpp"

#include "../logging/include/log.hpp"

Registrar::Registrar() {
    CND_REGISTRAR_TRACE("Constructing registrar....");
}

void Registrar::run() {
    CND_REGISTRAR_TRACE("Running in registrar mode....");
}

Registrar::~Registrar() {
    CND_REGISTRAR_TRACE("Destructing registrar....");
}

