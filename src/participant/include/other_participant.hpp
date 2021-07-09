#ifndef OTHER_PARTICIPANT_HPP
#define OTHER_PARTICIPANT_HPP

#include <string>

#include <sodium.h>

class OtherParticipant {
public:
    /// The ip (reachable) of the OP.
    char ip[200];
    /// The port of the OP.
    unsigned int port[10];
    /// The public key of the OP.
    unsigned char pubkey[crypto_box_PUBLICKEYBYTES];
};

#endif /* OTHER_PARTICIPANT_HPP */

