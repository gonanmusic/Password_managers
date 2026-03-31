#include <unistd.h>
#include "basic_function.h"
#include <openssl/sha.h>


char *encrypt_password_main(char *password)
{
    static char hex[SHA512_DIGEST_LENGTH * 2 + 1];
    unsigned char hash[SHA512_DIGEST_LENGTH];
    int i = 0; 
    const char *hex_chars = "0123456789abcdef";

    SHA512((unsigned char *)password, ft_strlen(password), hash);
    while (i < SHA512_DIGEST_LENGTH)
    {
        hex[i * 2] = hex_chars[hash[i] >> 4];    
        hex[i * 2 + 1] = hex_chars[hash[i] & 0x0F];
        i++;
    }
    hex[SHA512_DIGEST_LENGTH * 2] = '\0';

    return hex;
}