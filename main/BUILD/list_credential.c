/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_credential.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novella <novella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:36:33 by novella           #+#    #+#             */
/*   Updated: 2026/04/19 21:22:05 by novella          ###   ########.fr       */
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
    
    ft_putstr("Entrez votre mot de passe : ");
    ssize_t len = read_line(password, sizeof(password));
    
    password[len + 1] = '\0'; 
    
    if (len == -1)  
    {
        ft_putstr("Error while reading password");
        return (1);
    }
    if(connexion(password) != 0)
        ft_putstr("incorrect password");

    int fd = open("database.txt", O_RDONLY, 0644);
    if (fd == -1)
    {
        ft_putstr("Error, can't list your credentials");
        return (1);
    }
    
    char buffer[CHUNK_SIZE + 1];  
    ssize_t bytes_read;

    ft_putstr("Your Credential : \n");
    ft_putstr("\n");
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