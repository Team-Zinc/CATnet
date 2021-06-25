#ifndef WHISKER_EXCHANGE_HPP
#define WHISKER_EXCHANGE_HPP

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
};

#endif
