#ifndef WHISKER_EXCHANGE_HPP
#define WHISKER_EXCHANGE_HPP

#include <optional>
#include <tun.hpp>

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

/// The tun device that we use to capture packets,
/// to redirect them.
inline std::optional<TunDevice> m_tun;
};

#endif
