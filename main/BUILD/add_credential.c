/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_credential.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novella <novella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:36:04 by novella           #+#    #+#             */
/*   Updated: 2026/03/17 16:36:05 by novella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "basic_function.h"

struct credential *add_credential()
{
    struct credential *my_credential;

    my_credential = malloc(sizeof(struct credential));
    if (my_credential == NULL)
        return NULL;
    ft_putstr("Enter name site : \n");

    int len_site = 0; 
    char buffer_site[255]; 
    len_site = read(0, buffer_site, sizeof(buffer_site) - 1);
    if(len_site > 0)
    {
        buffer_site[len_site] = '\0';
        if(verif_format(buffer_site) == 1)
        {
            if (buffer_site[len_site - 1] == '\n')
                buffer_site[len_site - 1] = '\0';
        }
        else
        {
            ft_putstr("Wrong site format");
            free(my_credential);
            return NULL;
        }

        my_credential->site = malloc((len_site + 1) * sizeof(char));
        if(my_credential->site == NULL)
        {
            ft_putstr("Memory Allocation failed");
            free(my_credential);
            return NULL;
        }
        else
            ft_strcpy(my_credential->site, buffer_site);
    }
    else
    {
        ft_putstr("Wrong data format");
        free(my_credential);
        return NULL;
    }

    ft_putstr("Enter id : \n");
    int len_id = 0; 
    char buffer_id[255];
    len_id = read(0, buffer_id, sizeof(buffer_id) - 1);
    if(len_id > 0)
    {
        buffer_id[len_id] = '\0';
        if (buffer_id[len_id - 1] == '\n')
            buffer_id[len_id - 1] = '\0';
        my_credential->id = malloc((len_id +1) * sizeof(char));
        if(my_credential->id == NULL)
        {
            ft_putstr("Memory Allocation failed");
            free(my_credential->site);
            free(my_credential);
            return NULL;
        }
        else
            ft_strcpy(my_credential->id, buffer_id);
    }
    else 
    {
        ft_putstr("Wrong data format");
        free(my_credential->site);
        free(my_credential);
        return NULL;
    }

    ft_putstr("Enter password : \n");
    int len_password = 0;
    char buffer_password[255]; 
    len_password = read(0, buffer_password, sizeof(buffer_password) - 1);
    if(len_password > 0)
    {
        buffer_password[len_password] = '\0';
        if (buffer_password[len_password - 1] == '\n')
            buffer_password[len_password - 1] = '\0';

        my_credential->password = malloc((len_password + 1) * sizeof(char));
        
        if(my_credential->password == NULL)
        {
            ft_putstr("Memory Allocation failed");
            free(my_credential->site);
            free(my_credential->id);
            free(my_credential);
            return NULL;
        }
        else 
            ft_strcpy(my_credential->password, buffer_password); 
    }
    else
    {
        ft_putstr("Wrong data format");
        free(my_credential->site);
        free(my_credential->id);
        free(my_credential);
        return NULL;
    }
    return my_credential;

}