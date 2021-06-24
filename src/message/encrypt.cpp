#include "include/encrypt.hpp"

#include "include/message.hpp"
#include <cassert>
#include <cerrno>
#include <log.hpp>
#include <system_error>

SessionEncryptionState::SessionEncryptionState()
{
	// Make it so pages cannot be swapped to disk
	sodium_mlock(&m_our_sk, sizeof(m_our_sk));

	// Generate our keypair
	crypto_box_keypair(m_our_pk, m_our_sk);
}

void
SessionEncryptionState::set_other_private_key(
  unsigned char oth_pk[crypto_box_PUBLICKEYBYTES])
{
	memcpy(m_oth_pk, oth_pk, crypto_box_PUBLICKEYBYTES);
}

std::vector<unsigned char>
SessionEncryptionState::encrypt_message(std::vector<unsigned char> message)
{
	// Generate our nonce. Even though this is random number,
	// and there still *could* be collisions, it is such a small
	// chance that we do not need to worry. The docs say so, and so
	// do a large amount of other people.
	unsigned char nonce[crypto_box_NONCEBYTES];
	randombytes_buf(nonce, crypto_box_NONCEBYTES);
	std::vector<unsigned char> ret;

	unsigned char* ciphertext =
	  (unsigned char*)sodium_malloc(crypto_box_MACBYTES + message.size());
	if (ciphertext == nullptr) {
		throw std::system_error(errno, std::generic_category());
	}

	if (crypto_box_easy(ciphertext,
						message.data(),
						message.size(),
						nonce,
						m_our_pk,
						m_our_sk) == -1) {
		throw EncryptionException();
	}

	mutate_cstr_to_vector(*ciphertext, ret);
	return ret;
}

SessionEncryptionState::~SessionEncryptionState()
{
	// Completly zero the keys, and mark the pages as swappable again
	sodium_munlock(&m_our_sk, crypto_box_SECRETKEYBYTES);
}
