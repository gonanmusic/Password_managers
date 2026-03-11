#include <unistd.h>
#include <stdlib.h>
#include "basic_function.h"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        if(ft_strcmp(argv[1], "add") == 0)
        {

            struct credential *my_credential = add_credential();
            if (my_credential != NULL)
                write_credential(my_credential);
        }
        else if(ft_strcmp(argv[1], "list") == 0)
            list_credential(); 
        //else if(ft_strcmp(argv[1], "modify") == 0)
            //mod_credential(); 
        //else
            //ft_putstr("invalid command"); 
    }
    else
        ft_putstr("command missing : invalid format or two much arguments"); 
    return(0); 
}