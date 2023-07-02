#include "include/crypto/psa_crypto_mac.h"

psa_status_t iotex_psa_mac_abort(iotex_psa_mac_operation_t* operation)
{
	return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t iotex_psa_mac_sign_finish(iotex_psa_mac_operation_t* operation, uint8_t* mac,
									   size_t mac_size, size_t* mac_length)
{
	return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t iotex_psa_mac_sign_setup(iotex_psa_mac_operation_t* operation,
									  const psa_key_attributes_t* attributes,
									  const uint8_t* key_buffer, size_t key_buffer_size,
									  psa_algorithm_t alg)
{
	return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t iotex_psa_mac_update(iotex_psa_mac_operation_t* operation, const uint8_t* input,
								  size_t input_length)
{
	return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t iotex_psa_mac_verify_finish(iotex_psa_mac_operation_t* operation, const uint8_t* mac,
										 size_t mac_length)
{
	return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t iotex_psa_mac_verify_setup(iotex_psa_mac_operation_t* operation,
										const psa_key_attributes_t* attributes,
										const uint8_t* key_buffer, size_t key_buffer_size,
										psa_algorithm_t alg)
{
	return PSA_ERROR_NOT_SUPPORTED;
}

psa_status_t iotex_psa_mac_compute(const psa_key_attributes_t* attributes,
								   const uint8_t* key_buffer, size_t key_buffer_size,
								   psa_algorithm_t alg, const uint8_t* input, size_t input_length,
								   uint8_t* mac, size_t mac_size, size_t* mac_length)
{
	return PSA_ERROR_NOT_SUPPORTED;
}
