#ifndef STATE_HPP
#define STATE_HPP

#include <other_participant.hpp>
#include <vector>

/// Holds the state of the cat. This means all
/// conected participants, their ips, public keys, etc...
class CatState {
    public:
        static void add_participant(OtherParticipant other) { m_participants.push_back(other); };
    private:
        inline static std::vector<OtherParticipant> m_participants;
};

#endif /* STATE_HPP */

