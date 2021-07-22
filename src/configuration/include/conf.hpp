/// What the hell is a configuration singleton?
/// Well, every thing related to configurating CATnet
/// belongs here. It should be written from inside the
/// library itself.

#ifndef CONF_HPP
#define CONF_HPP

#include <map>
#include <memory>
#include <string>

/// Participant shit
/// The port to communite with other whiskers on.
#define P_PORT 0

/// Registrar shit
/// The port to listen on for whisker connections.
#define R_PORT 0

namespace Configuration {
    /// Configuration for the participant.
    inline std::map<uintptr_t, uintptr_t> participant_config;

    /// Configuration for the registrar.
    inline std::map<uintptr_t, uintptr_t> registrar_config;

    void InitConfiguration();
};

#endif /* CONF_HPP */
