#include <unistd.h>
#include "basic_function.h"
#define CHUNK_SIZE 1024

int is_already_saved(char *str)
{
    int fd = open("database.txt", O_RDONLY);
    if(fd == - 1)
    {
        ft_putstr("Error accessing credential");
        return(1); 
    }

    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, CHUNK_SIZE)))  
    {
        while
            buffer[bytes_read] = '\0';  
            int temp1 = ft_strcmp(buffer, str);

        if(temp1 == 0)
            return(1);     
    }
    return(0); 
}
