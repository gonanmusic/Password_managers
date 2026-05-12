#include <unistd.h>
#include <stdlib.h>
#include "basic_function.h"

void    ui_main()
{
    ft_putstr("**************");
    write(1, "\n", 1);
    ft_putstr("Welcome to your password managers.");
    write(1, "\n", 1);
    ft_putstr("**************");
    write(1, "\n", 1);
    write(1, "\n", 1);
    ft_putstr("Choose one option bellow : ");
    write(1, "\n", 1);
    ft_putstr("0. Add credential");
    write(1, "\n", 1);
    ft_putstr("1. List credentials");
    write(1, "\n", 1);
    ft_putstr("2. Modify your credential"); 
    write(1, "\n", 1);
    write(1, "\n", 1);
    ft_putstr("(Tape the number that correspond your needs)");
    write(1, "\n", 1);
    write(1, "\n", 1); 
    ft_putstr("**************"); 
    write(1, "\n", 1); 
}

void    credential_saved()
{
    write(1, "\n", 1);
    ft_putstr("**************");
    write(1, "\n", 1);
    ft_putstr("Credential saved !");
    write(1, "\n", 1);
    ft_putstr("**************");
    write(1, "\n", 1);
};

