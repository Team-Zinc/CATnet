#ifndef WHISKER_EXCHANGE_HPP
#define WHISKER_EXCHANGE_HPP

#include <tun.hpp>
#include <optional>

/// Contains all the state information needed exchange with another whisker.
class WhiskerExchange
{
  public:
	/// Construct a #WhiskerExchange.
	static void init();

	/// Destroy a #WhiskerExchange.
	static void destroy();

	/// Run, using the state.
	static void run();

  private:
    /// The tun device that we use to capture packets,
    /// to redirect them.
    inline static std::optional<TunDevice> m_tun;
};

#endif
