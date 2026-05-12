/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_connexion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novella <novella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:36:29 by novella           #+#    #+#             */
/*   Updated: 2026/04/19 21:34:04 by novella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "basic_function.h"

char *first_connexion()
{
    static char final_password[256];
    char buffer[256];
    int fd;
    ssize_t len;
    int i;
    int j;

    fd = open("password_main", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        ft_putstr("Problem finding PASSWORD");
        return(NULL);
    }

    ft_putstr("Create password \n");
    ft_putstr("Choose a password with at least 8 characters : ");
    len = read_line(buffer, sizeof(buffer));
    if (len <= 7)
    {
        close(fd);
        ft_putstr("Impossible to read password"); 
        return(NULL);
    }
    i = 0;
    while (buffer[i])
        i++;

    j = 0;
    while (buffer[j])
    {
        final_password[j] = buffer[j];
        j++;
    }
    final_password[j] = '\0';
    
    char *final_password_encrypted = encrypt_password_main(final_password);

    write(fd, final_password_encrypted, ft_strlen(final_password_encrypted));
    write(fd, "\n", 1);        
    close(fd);
    return (final_password_encrypted);
}