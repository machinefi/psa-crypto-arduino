#include "PSACrypto.h"

void setup()
{
	Serial.begin(115200);
	delay(1000);
	Serial.println();

	Serial.println("W3bstream SDK example: Random number generation");
	Serial.println(
		"This example shows how to use the W3bstream PSA Crypto API to generate random values.");
	Serial.println("Note: This example is only for demonstration purposes. Production applications "
				   "should seed the random generator with enough entropy.");
	Serial.println("      PIN1 analog read is used as the entropy source, so the random generated "
				   "values will be the same between boots unless the state of pin 1 changes.");
	Serial.println("--------------------------------------------------------------------\n");

	// Initialize the library.
	psa_crypto_init();

	// Set the random generator seed.
	// Note: This is only for demonstration purposes and not a true random seed.
	// The random seed should be set to a true random value in a production application.
	int pseudoRandomSeed = analogRead(1);
	randomSeed(pseudoRandomSeed);
	SetEntropy(random(255));

	// Generate 10 random bytes.
	Serial.println("Generating 10 random bytes");
	uint8_t random[10] = {0};
	psa_status_t status = psa_generate_random(random, sizeof(random));
	if(status != PSA_SUCCESS)
	{
		Serial.println("Error: psa_generate_random failed.");
		Serial.print("Status code: ");
		Serial.println(status);
		return;
	}

	// Print the random bytes.
	Serial.println("Random bytes: ");
	for(int i = 0; i < sizeof(random); i++)
	{
		if(random[i] < 0x10)
			Serial.print("0");
		Serial.print(random[i], HEX);
		Serial.print(" ");
		if((i + 1) % 16 == 0)
			Serial.println();
	}
}

void loop()
{
}
