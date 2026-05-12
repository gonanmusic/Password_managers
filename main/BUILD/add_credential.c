/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_credential.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novella <novella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:36:04 by novella           #+#    #+#             */
/*   Updated: 2026/04/19 21:36:13 by novella          ###   ########.fr       */
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
    len_site = read_line(buffer_site, sizeof(buffer_site));
    if(len_site > 0)
    {
        if(verif_format(buffer_site) == 1)
        {
        }
        else
        {
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
    len_id = read_line(buffer_id, sizeof(buffer_id));
    if(len_id > 0)
    {
        my_credential->id = malloc((len_id +1) * sizeof(char));
        if(my_credential->id == NULL)
        {
            ft_putstr("Memory Allocation failed");
            free(my_credential->site);
            free(my_credential);
            return NULL;
        }
        //else if(my_credential->id != NULL)
       // {
            //char temp[255];  
            //ft_strcpy(temp, my_credential->id);
            //char temp2[255]; 
            //ft_strcpy(temp2, my_credential->site); 
            //if(is_already_saved(temp) == 0 && is_already_saved(temp2) == 0)
        ft_strcpy(my_credential->id, buffer_id);
            //else 
            //return NULL; 
       // }             
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
    len_password = read_line(buffer_password, sizeof(buffer_password));
    if(len_password > 0)
    {

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