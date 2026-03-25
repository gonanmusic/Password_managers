/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_credential.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novella <novella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:36:33 by novella           #+#    #+#             */
/*   Updated: 2026/03/17 16:36:34 by novella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "basic_function.h"
#define CHUNK_SIZE 1024

int list_credential()
{
    char password[100];

    if (access("password_main", F_OK) == -1)
        first_connexion();

    ft_putstr("Entrez votre mot de passe : ");
    int fd1 = read(0, password, 99);
    if (fd1 == -1)  
    {
        ft_putstr("Error while reading password");
        return (1);
    }
    password[strcspn(password, "\n")] = '\0';

    if (connexion(password) != 0)
    {
        ft_putstr("invalid password");
        return (1);
    }

    int fd = open("database.txt", O_RDONLY, 0644);
    if (fd == -1)
    {
        ft_putstr("Error, can't list your credentials");
        return (1);
    }

    char buffer[CHUNK_SIZE + 1];  
    ssize_t bytes_read;

    ft_putstr("Your Credential : \n");
    while ((bytes_read = read(fd, buffer, CHUNK_SIZE)) > 0)  
    {
        buffer[bytes_read] = '\0';  
        ft_putstr(buffer);
    }

    if (bytes_read == -1)
    {
        ft_putstr("Error while reading file");
        close(fd);
        return (1);
    }

    close(fd);
    return (0);
}