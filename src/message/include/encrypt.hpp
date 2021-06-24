#ifndef ENCRYPT_HPP
#define ENCRYPT_HPP

#include <exception>
#include <sodium.h>
#include <vector>

struct DecryptionException : public std::exception
{
	const char* what() const throw() { return "Failed to dencrypt message"; }
};

struct EncryptionException : public std::exception
{
	const char* what() const throw() { return "Failed to encrypt message"; }
};

/// Contains state information nessisary for encryption and decryption
class SessionEncryptionState
{
  public:
	SessionEncryptionState();
	~SessionEncryptionState();

	void set_other_private_key(unsigned char oth_pk[crypto_box_PUBLICKEYBYTES]);
	std::vector<unsigned char> encrypt_message(
	  std::vector<unsigned char> message);

	unsigned char* get_our_pk() { return m_our_pk; };

  private:
	unsigned char m_our_pk[crypto_box_PUBLICKEYBYTES];
	unsigned char m_our_sk[crypto_box_SECRETKEYBYTES];
	unsigned char m_oth_pk[crypto_box_PUBLICKEYBYTES];
};

#endif /* ENCRYPT_HPP */
