#include <unistd.h>
#include <stdlib.h>
#include "basic_function.h"

int is_first_connexion()
{
    int fd = open("password_main", O_RDONLY, 0644);
    close(fd); 
    return(fd); 
}
