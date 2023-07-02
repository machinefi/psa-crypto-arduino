#include "PSACrypto.h"

void setup()
{
	Serial.begin(115200);
	delay(1000);
	Serial.println();

	Serial.println("W3bstream SDK example: Hash");
	Serial.println("This example shows how to use the W3bstream PSA Crypto API compute and "
				   "validate a hash using a one shot operation.");
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

	// Compute the hash using SHA256.
	status = psa_hash_compute(PSA_ALG_SHA_256, message, sizeof(message), hash, sizeof(hash),
							  &hashLenght);

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

	// Verify the hash
	status = psa_hash_compare(PSA_ALG_SHA_256, message, sizeof(message), hash, hashLenght);
	if(status != PSA_SUCCESS)
	{
		Serial.println("Error: psa_hash_compare failed.");
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
