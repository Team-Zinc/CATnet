#ifndef PARTICIPANT_HPP
#define PARTICIPANT_HPP

#include <thread>

class Participant
{
  public:
	Participant();
	~Participant();
	void run();

  private:
	std::thread m_RegistrarExchangeThread;
	std::thread m_WhiskerExchangeThread;
};

#endif
