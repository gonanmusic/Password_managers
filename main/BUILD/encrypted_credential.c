#include <unistd.h>
#include "basic_function.h"
#include <openssl/sha.h>


unsigned char *encrypt_password(char *password)
{
    unsigned char hash[SHA512_DIGEST_LENGTH];
    return SHA512((unsigned char*)password, ft_strlen(password), hash);
}
