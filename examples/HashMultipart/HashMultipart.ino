#include "PSACrypto.h"

void setup()
{
	Serial.begin(115200);
	delay(1000);
	Serial.println();

	Serial.println(
		"W3bstream SDK example: Hash multi-part (streaming) computation and verification");
	Serial.println("This example shows how to use the W3bstream PSA Crypto API compute and "
				   "validate a hash using a multi-part (streaming) operation.");
	Serial.println("--------------------------------------------------------------------\n");

	// Initialize the library.
	psa_crypto_init();

	// Define a variable status that will be used to store the result of the PSA API calls.
	psa_status_t status = PSA_SUCCESS;

	// The data to hash.
	uint8_t message[4] = {0x01, 0x02, 0x03, 0x04};

	// A buffer where the computed hash will be stored.
	uint8_t hash[32] = {0};

	// A variable where the length of the computed hash will be stored.
	size_t hashLenght = 0;

	// Setup the hash compute operation.
	psa_hash_operation_t computeOperation = PSA_HASH_OPERATION_INIT;
	psa_crypto_init();
	psa_hash_setup(&computeOperation, PSA_ALG_SHA_256);

	// Compute the hash in two steps of two bytes each.
	status = psa_hash_update(&computeOperation, message, 2);
	if(status != PSA_SUCCESS)
	{
		Serial.println("Error: psa_hash_update failed.");
		Serial.print("Status code: ");
		Serial.println(status);
		return;
	}
	status = psa_hash_update(&computeOperation, message + 2, 2);
	if(status != PSA_SUCCESS)
	{
		Serial.println("Error: psa_hash_update failed.");
		Serial.print("Status code: ");
		Serial.println(status);
		return;
	}
	status = psa_hash_finish(&computeOperation, hash, sizeof(hash), &hashLenght);
	if(status != PSA_SUCCESS)
	{
		Serial.println("Error: psa_hash_finish failed.");
		Serial.print("Status code: ");
		Serial.println(status);
		return;
	}

	// Print the message and the computed hash.
	Serial.print("Message: ");
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
	Serial.print("Hash (");
	Serial.print(hashLenght);
	Serial.println(" bytes):");
	for(int i = 0; i < sizeof(hash); i++)
	{
		if(hash[i] < 0x10)
			Serial.print("0");
		Serial.print(hash[i], HEX);
		Serial.print(" ");
		if((i + 1) % 16 == 0)
			Serial.println();
	}
	Serial.println();

	// Verify the hash.
	psa_hash_operation_t verifyOperation = PSA_HASH_OPERATION_INIT;
	psa_hash_setup(&verifyOperation, PSA_ALG_SHA_256);
	status = psa_hash_update(&verifyOperation, message, sizeof(message));
	if(status != PSA_SUCCESS)
	{
		Serial.println("Error: psa_hash_update failed.");
		Serial.print("Status code: ");
		Serial.println(status);
		return;
	}
	status = psa_hash_verify(&verifyOperation, hash, hashLenght);
	if(status != PSA_SUCCESS)
	{
		Serial.println("Error: psa_hash_verify failed.");
		Serial.print("Status code: ");
		Serial.println(status);
		return;
	}
	else
	{
		Serial.println("Hash verified successfully.");
	}
}

void loop()
{
}
