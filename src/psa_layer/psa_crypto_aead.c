#include "include/crypto/psa_crypto_aead.h"

psa_status_t iotex_psa_aead_decrypt(const psa_key_attributes_t* attributes,
									const uint8_t* key_buffer, size_t key_buffer_size,
									psa_algorithm_t alg, const uint8_t* nonce, size_t nonce_length,
									const uint8_t* additional_data, size_t additional_data_length,
									const uint8_t* ciphertext, size_t ciphertext_length,
									uint8_t* plaintext, size_t plaintext_size,
									size_t* plaintext_length)
{
	return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t iotex_psa_aead_decrypt_setup(iotex_psa_aead_operation_t* operation,
										  const psa_key_attributes_t* attributes,
										  const uint8_t* key_buffer, size_t key_buffer_size,
										  psa_algorithm_t alg)
{
	return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t iotex_psa_aead_set_nonce(iotex_psa_aead_operation_t* operation, const uint8_t* nonce,
									  size_t nonce_length)
{
	return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t iotex_psa_aead_update_ad(iotex_psa_aead_operation_t* operation, const uint8_t* input,
									  size_t input_length)
{
	return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t iotex_psa_aead_encrypt(const psa_key_attributes_t* attributes,
									const uint8_t* key_buffer, size_t key_buffer_size,
									psa_algorithm_t alg, const uint8_t* nonce, size_t nonce_length,
									const uint8_t* additional_data, size_t additional_data_length,
									const uint8_t* plaintext, size_t plaintext_length,
									uint8_t* ciphertext, size_t ciphertext_size,
									size_t* ciphertext_length)
{
	return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t iotex_psa_aead_encrypt_setup(iotex_psa_aead_operation_t* operation,
										  const psa_key_attributes_t* attributes,
										  const uint8_t* key_buffer, size_t key_buffer_size,
										  psa_algorithm_t alg)
{
	return PSA_ERROR_NOT_SUPPORTED;
}
