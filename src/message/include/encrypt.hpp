#ifndef ENCRYPT_HPP
#define ENCRYPT_HPP

#include <exception>
#include <sodium.h>
#include <vector>

/// Contains state information nessisary for encryption and decryption.
/// Despite it's name, it is used for decyption also.
class SessionEncryptionState
{
  public:
	/// Constructs a SessionEncryptionState
	SessionEncryptionState();
	/// Destructs a SessionEncrpytionState
	~SessionEncryptionState();

	/// Sets the publib key of the other party.
	/// For example, if this is running on the registrar,
	/// this function would be called with the participants
	/// public key.
	void set_other_public_key(unsigned char oth_pk[crypto_box_PUBLICKEYBYTES]);

	/// Encrypts a message, and then return it.
	int encrypt_message(std::vector<unsigned char> message, std::vector<unsigned char>* buf);

	/// Getter function for our public key.
	/// For example, if this is running on the participant,
	/// this would return that participants public key.
	unsigned char* get_our_pk() { return m_our_pk; };

  private:
	/// Our public key.
	unsigned char m_our_pk[crypto_box_PUBLICKEYBYTES];
	/// Our secret key.
	unsigned char m_our_sk[crypto_box_SECRETKEYBYTES];
	/// Other (or their) public key.
	unsigned char m_oth_pk[crypto_box_PUBLICKEYBYTES];
};

#endif /* ENCRYPT_HPP */
