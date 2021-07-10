#ifndef PARTICIPANT_HPP
#define PARTICIPANT_HPP

#include <thread>

/// Contains enough state information to kick of the
/// Registrar and whisker exchange threads.
namespace Participant {
/// Constructs a Participant.
void
init();

/// Destructs a Particpant.
void
destroy();

/// Creates registrar and whisker exchange threads, and runs them.
void
run();
};

#endif
