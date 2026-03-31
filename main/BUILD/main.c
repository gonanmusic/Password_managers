/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novella <novella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:36:35 by novella           #+#    #+#             */
/*   Updated: 2026/03/31 13:26:16 by novella          ###   ########.fr       */
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
    char password[255]; 
    int is_connected = 0;
    char entry[2];     
    ui_main(); 
    
    read(0, entry, 1); 
    
    if(ft_strcmp(entry, "0") == 0)
    {
        system("@cls||clear");
        
        if(is_first_connexion() <= 0)
            first_connexion();
        else
        {
            ft_putstr("Enter password :");
            read(0, password, 129);
            password[strcspn(password, "\n")] = '\0';
            is_connected = connexion(password);
            
            if(is_connected == 0)
            {
                struct credential *my_credential = add_credential();
                if (my_credential != NULL)
                write_credential(my_credential);
            }
            else
                ft_putstr("Wrong Password"); 
        }
    }
    else if(ft_strcmp(entry, "1") == 0)
        list_credential(); 
        // else if(ft_strcmp(argv[1], "modify") == 0)
        //     mod_credential();  // Function not implemented yet
    else
        ft_putstr("invalid command"); 
    return(0); 
}