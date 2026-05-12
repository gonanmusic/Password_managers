#include <unistd.h>
#include "basic_function.h"

char *decrypted_password_main(char *password_entered)
{
    return encrypt_password_main(password_entered);
}