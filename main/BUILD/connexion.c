/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novella <novella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:36:25 by novella           #+#    #+#             */
/*   Updated: 2026/04/19 21:28:38 by novella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "basic_function.h"

int connexion(char *str)
{
    int fd;
    char stored[129];
    //int i;
    ssize_t len;

    fd = open("password_main", O_RDONLY, 0644);
    if (fd == -1)
    {
        ft_putstr("Can't find the file");
        return(1); 
    }
    
    len = read(fd, stored, sizeof(stored) - 1);
    if (len <= 0)
    {
        close(fd);
        return (1);
    }
    stored[len] = '\0';

   //i = 0;
    /*while (stored[i] && stored[i] != '\n')
        i++;
    stored[i] = '\0';
    */

    close(fd);
    
    char *hash = decrypted_password_main(str);

    if (ft_strcmp(hash, stored) != 0)
        return (1);
    return (0);
}