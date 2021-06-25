#ifndef PARTICIPANT_HPP
#define PARTICIPANT_HPP

#include <thread>

/// Contains enough state information to kick of the
/// Registrar and whisker exchange threads.
class Participant
{
  public:
	/// Constructs a Participant.
	Participant();
	/// Destructs a Particpant.
	~Participant();
	/// Creates registrar and whisker exchange threads, and runs them.
	void run();

  private:
	/// Thread for registrar intercommunication.
	std::thread m_RegistrarExchangeThread;
	/// Thread for whisker intercommunication.
	std::thread m_WhiskerExchangeThread;
};

#endif
