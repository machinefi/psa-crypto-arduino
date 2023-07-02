# CMake 3.10: Ubuntu 20.04.
# https://cliutils.gitlab.io/modern-cmake/chapters/intro/dodonot.html
cmake_minimum_required(VERSION 3.16)

# If you set any CMAKE_ variables, that can go here.
# (But usually don't do this, except maybe for C++ standard)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
  PSACrypto
  VERSION 1.0
  LANGUAGES C CXX
)

add_library(psa_crypto STATIC)
target_include_directories(psa_crypto 
    PUBLIC src
)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.c src/*.h)

target_sources(psa_crypto 
  PRIVATE
    src/psa_layer/psa_crypto_cipher.c
    src/psa_layer/psa_crypto_client.c
    src/psa_layer/psa_crypto_driver_wrappers.c
    src/psa_layer/psa_crypto_ecp.c
    src/psa_layer/psa_crypto_ecdh.c
    src/psa_layer/psa_crypto_hash.c
    src/psa_layer/psa_crypto_aead.c
    src/psa_layer/psa_crypto_rsa.c
    src/psa_layer/psa_crypto_mac.c
    src/psa_layer/psa_crypto_slot_management.c
    src/psa_layer/cipher_wrap.c
    src/psa_layer/psa_crypto.c
    src/psa_layer/psa_crypto_porting.c
    src/psa_layer/entropy.c
    src/tinycrypt/aes_decrypt.c
    src/tinycrypt/aes_encrypt.c
    src/tinycrypt/cbc_mode.c
    src/tinycrypt/ccm_mode.c
    src/tinycrypt/cmac_mode.c
    src/tinycrypt/ctr_mode.c
    src/tinycrypt/ctr_prng.c
    src/tinycrypt/ecc_dh.c
    src/tinycrypt/ecc_dsa.c
    src/tinycrypt/ecc_platform_specific.c
    src/tinycrypt/ecc.c
    src/tinycrypt/hmac_prng.c
    src/tinycrypt/hmac.c
    src/tinycrypt/sha256.c
    src/tinycrypt/utils.c
)

include(CTest)
if (BUILD_TESTING)
  target_compile_definitions(psa_crypto PUBLIC -DUNIT_TEST_BUILD)
  include(FetchContent) 
  FetchContent_Declare(
    googletest
    # Specify the commit you depend on and update it regularly.
    URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
  )
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

    add_executable(unit_tests 
      tests/test_psa_cipher_encrypt.cpp
      tests/test_psa_cipher_decrypt.cpp
      tests/test_psa_cipher_decrypt_setup.cpp
      tests/test_psa_cipher_encrypt_setup.cpp
      tests/test_psa_cipher_generate_iv.cpp
      tests/test_psa_cipher_update.cpp
      tests/test_psa_copy_key.cpp
      tests/test_psa_crypto_init.cpp
      tests/test_psa_destroy_key.cpp
      tests/test_psa_export_key.cpp
      tests/test_psa_export_public_key.cpp
      tests/test_psa_generate_key.cpp
      tests/test_psa_generate_random.cpp
      tests/test_psa_hash_abort.cpp
      tests/test_psa_hash_clone.cpp
      tests/test_psa_hash_compare.cpp
      tests/test_psa_hash_compute.cpp
      tests/test_psa_hash_finish.cpp
      tests/test_psa_hash_setup.cpp
      tests/test_psa_hash_update.cpp
      tests/test_psa_hash_verify.cpp
      tests/test_psa_import_key.cpp
    )

    target_link_libraries(unit_tests
      psa_crypto
      gtest_main)

    add_test(NAME unit_tests COMMAND unit_tests)

    list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")

endif()