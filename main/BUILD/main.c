/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novella <novella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:36:35 by novella           #+#    #+#             */
/*   Updated: 2026/04/19 21:17:59 by novella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "basic_function.h"

int main()
{
    char password[129]; 
    char entry[3]; 
    ssize_t len_password;
    ssize_t len_entry;
    
    if(is_first_connexion() == 1)
    {
        if(first_connexion() == NULL)
            return(1);
    }
    ft_putstr("Enter password :");
    len_password = read_line(password, sizeof(password));
    if (len_password <= 0)
    {
        ft_putstr("Error while reading password");
        return (1);
    }
    if(connexion(password) != 0)
    {
        ft_putstr("Invalid Password");
        return(1);
    }
    ui_main(); 
    len_entry = read_line(entry, sizeof(entry));
    if (len_entry <= 0)
    {
        ft_putstr("invalid command");
        return (1);
    }
    if(ft_strcmp(entry, "0") == 0)
    {
        system("@cls||clear");
        struct credential *my_credential = add_credential();
        
        if (my_credential == NULL)
        {
            ft_putstr("Allocation failed");
            return(1);
        } 
        write_credential(my_credential);
        system("@cls||clear");  
        credential_saved();         
    }
    else if(ft_strcmp(entry, "1") == 0)
        list_credential();    
    else
        ft_putstr("invalid command");
    return(0); 
}