#include "include/iotex/ecdh.h"
#include "include/iotex/error.h"

void iotex_ecdh_free(iotex_ecdh_context* ctx)
{
	return;
}

int iotex_ecdh_can_do(iotex_ecp_group_id gid)
{
	return IOTEX_ERR_PLATFORM_FEATURE_UNSUPPORTED;
}

int iotex_ecdh_gen_public(iotex_ecp_group* grp, iotex_mpi* d, iotex_ecp_point* Q,
						  int (*f_rng)(void*, unsigned char*, size_t), void* p_rng)
{
	return IOTEX_ERR_PLATFORM_FEATURE_UNSUPPORTED;
}

int iotex_ecdh_compute_shared(iotex_ecp_group* grp, iotex_mpi* z, const iotex_ecp_point* Q,
							  const iotex_mpi* d, int (*f_rng)(void*, unsigned char*, size_t),
							  void* p_rng)
{
	return IOTEX_ERR_PLATFORM_FEATURE_UNSUPPORTED;
}

void iotex_ecdh_init(iotex_ecdh_context* ctx)
{
	return;
}

int iotex_ecdh_setup(iotex_ecdh_context* ctx, iotex_ecp_group_id grp_id)
{
	return IOTEX_ERR_PLATFORM_FEATURE_UNSUPPORTED;
}

int iotex_ecdh_make_params(iotex_ecdh_context* ctx, size_t* olen, unsigned char* buf, size_t blen,
						   int (*f_rng)(void*, unsigned char*, size_t), void* p_rng)
{
	return IOTEX_ERR_PLATFORM_FEATURE_UNSUPPORTED;
}

int iotex_ecdh_read_params(iotex_ecdh_context* ctx, const unsigned char** buf,
						   const unsigned char* end)
{
	return IOTEX_ERR_PLATFORM_FEATURE_UNSUPPORTED;
}

int iotex_ecdh_get_params(iotex_ecdh_context* ctx, const iotex_ecp_keypair* key,
						  iotex_ecdh_side side)
{
	return IOTEX_ERR_PLATFORM_FEATURE_UNSUPPORTED;
}

int iotex_ecdh_make_public(iotex_ecdh_context* ctx, size_t* olen, unsigned char* buf, size_t blen,
						   int (*f_rng)(void*, unsigned char*, size_t), void* p_rng)
{
	return IOTEX_ERR_PLATFORM_FEATURE_UNSUPPORTED;
}

int iotex_ecdh_read_public(iotex_ecdh_context* ctx, const unsigned char* buf, size_t blen)
{
	return IOTEX_ERR_PLATFORM_FEATURE_UNSUPPORTED;
}

int iotex_ecdh_calc_secret(iotex_ecdh_context* ctx, size_t* olen, unsigned char* buf, size_t blen,
						   int (*f_rng)(void*, unsigned char*, size_t), void* p_rng)
{
	return IOTEX_ERR_PLATFORM_FEATURE_UNSUPPORTED;
}

void iotex_ecdh_enable_restart(iotex_ecdh_context* ctx)
{
	return;
}
