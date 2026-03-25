/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novella <novella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:36:25 by novella           #+#    #+#             */
/*   Updated: 2026/03/25 14:08:33 by novella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "basic_function.h"

int connexion(char *str)
{
    int fd;
    char stored[256];
    int i;
    ssize_t len;

    fd = open("password_main", O_RDONLY, 0644);
    if (fd == -1)
    {
        return(1); 
    }
    
    len = read(fd, stored, sizeof(stored) - 1);
    if (len <= 0)
    {
        close(fd);
        return (1);
    }
    stored[len] = '\0';

    i = 0;
    while (stored[i] && stored[i] != '\n')
        i++;
    stored[i] = '\0';

    close(fd);

    if (ft_strcmp(str, stored) == 0)
        return (0);
    return (1);
}