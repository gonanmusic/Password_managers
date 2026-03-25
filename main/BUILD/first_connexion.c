/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_connexion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novella <novella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:36:29 by novella           #+#    #+#             */
/*   Updated: 2026/03/18 13:31:39 by novella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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
        return (NULL);
    }

    ft_putstr("Create password : ");
    len = read(0, buffer, sizeof(buffer) - 1);
    if (len <= 0)
    {
        close(fd);
        ft_putstr("Password need to be one character or higher");
        return (NULL);
    }
    buffer[len] = '\0';

    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    buffer[i] = '\0';

    j = 0;
    while (buffer[j])
    {
        final_password[j] = buffer[j];
        j++;
    }
    final_password[j] = '\0';

    write(fd, final_password, j);
    write(fd, "\n", 1);
    close(fd);

    return (final_password);
}