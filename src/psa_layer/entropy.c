#include "include/entropy.h"
#include "include/tinycrypt/ecc_platform_specific.h"

void SetEntropy(uint8_t seed)
{
	default_SetSeed(seed);
}