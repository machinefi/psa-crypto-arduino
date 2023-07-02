#include "PSACrypto.h"

void setup()
{
	Serial.begin(115200);
	delay(1000);
	Serial.println();

	Serial.println("W3bstream SDK example: Sign message");
	Serial.println("This example shows how to use the W3bstream PSA Crypto API to sign a message "
				   "using the Secp256r1 Elliptic Curve.");
	Serial.println("--------------------------------------------------------------------\n");

	// Initialize the library.
	psa_crypto_init();

	// Define a variable status that will be used to store the result of the PSA API calls.
	psa_status_t status = PSA_SUCCESS;

	// Define a variable that will be used to store the key identifier.
	psa_key_id_t keyId = 0;

	// Generate an ECDS SECP256R1 key pair.
	Serial.println("Generating a key pair");
	psa_key_attributes_t keyAttributes = PSA_KEY_ATTRIBUTES_INIT;
	psa_set_key_usage_flags(&keyAttributes, PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_VERIFY_HASH |
												PSA_KEY_USAGE_EXPORT);
	psa_set_key_algorithm(&keyAttributes, PSA_ALG_ECDSA(PSA_ALG_SHA_256));
	psa_set_key_type(&keyAttributes, PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1));
	psa_set_key_bits(&keyAttributes, 256);
	status = psa_generate_key(&keyAttributes, &keyId);
	if(status != PSA_SUCCESS)
	{
		Serial.println("Error: psa_generate_key failed.");
		Serial.print("Status code: ");
		Serial.println(status);
		return;
	}

	// Print the key bytes as a hex string.
	uint8_t key[32] = {0};
	size_t keyLength = 0;
	status = psa_export_key(keyId, key, sizeof(key), &keyLength);
	if(status != PSA_SUCCESS)
	{
		Serial.println("Error: psa_export_key failed.");
		Serial.print("Status code: ");
		Serial.println(status);
		return;
	}
	Serial.println("Key: ");
	for(int i = 0; i < keyLength; i++)
	{
		if(key[i] < 0x10)
			Serial.print("0");
		Serial.print(key[i], HEX);
		Serial.print(" ");
		if((i + 1) % 16 == 0)
			Serial.println();
	}

	// Sign a message.
	uint8_t message[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
	Serial.println("Signing message:");
	for(int i = 0; i < sizeof(message); i++)
	{
		if(message[i] < 0x10)
			Serial.print("0");
		Serial.print(message[i], HEX);
		Serial.print(" ");
		if((i + 1) % 16 == 0)
			Serial.println();
	}
	Serial.println();
	uint8_t signature[64] = {0};
	size_t signatureLength = 0;
	status = psa_sign_message(keyId, PSA_ALG_ECDSA(PSA_ALG_SHA_256), message, sizeof(message),
							  signature, sizeof(signature), &signatureLength);
	if(status != PSA_SUCCESS)
	{
		Serial.println("Error: psa_sign_message failed.");
		Serial.print("Status code: ");
		Serial.println(status);
		return;
	}

	// Print the signature.
	Serial.println("Signature: ");
	for(int i = 0; i < signatureLength; i++)
	{
		if(signature[i] < 0x10)
			Serial.print("0");
		Serial.print(signature[i], HEX);
		Serial.print(" ");
		if((i + 1) % 16 == 0)
			Serial.println();
	}

	// Verify the signature.
	Serial.println("Verifying signature");
	status = psa_verify_message(keyId, PSA_ALG_ECDSA(PSA_ALG_SHA_256), message, sizeof(message),
								signature, signatureLength);
	if(status != PSA_SUCCESS)
	{
		Serial.println("Error: psa_verify_message failed.");
		Serial.print("Status code: ");
		Serial.println(status);
		return;
	}
	Serial.println("Signature verified successfully");
}

void loop()
{
	delay(1000);
}
