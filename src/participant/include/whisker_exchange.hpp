#ifndef WHISKER_EXCHANGE_HPP
#define WHISKER_EXCHANGE_HPP

#include <optional>
#include <tap.hpp>

/// Contains all the state information needed exchange with another whisker.
namespace WhiskerExchange {
/// Construct a #WhiskerExchange.
void
init();

/// Destroy a #WhiskerExchange.
void
destroy();

/// Run, using the state.
int
run();

/// The tap device that we use to capture packets,
/// to redirect them.
inline std::optional<TapDevice> m_tap;
};

#endif
