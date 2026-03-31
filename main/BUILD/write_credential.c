/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_credential.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novella <novella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:36:39 by novella           #+#    #+#             */
/*   Updated: 2026/03/26 13:22:09 by novella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "basic_function.h"

int write_credential(struct credential *my_credential)
{
    int file_descriptor = open("database.txt", O_RDWR | O_CREAT | O_APPEND, 0644 ); 

    if (file_descriptor == -1)
    {
        ft_putstr("Error Opening File"); 
        return(-1); 
    }
    else
    {
        //unsigned char *encrypted_password = encrypt_password(my_credential ->password); 
        
        write(file_descriptor, my_credential->site, ft_strlen(my_credential->site));
        write(file_descriptor, "|", 1);
        write(file_descriptor, my_credential->id, ft_strlen(my_credential->id));
        write(file_descriptor, "|", 1);
        write(file_descriptor, my_credential->password, ft_strlen(my_credential->password)); 
        write(file_descriptor, "\n", 1);
    }
    close(file_descriptor);
    free_credential(my_credential);
    return(0);
}