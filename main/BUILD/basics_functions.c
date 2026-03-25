/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novella <novella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:36:21 by novella           #+#    #+#             */
/*   Updated: 2026/03/17 16:36:22 by novella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "basic_function.h"

int ft_strcmp(char *s1, char *s2 )
{
    unsigned int i = 0; 

    while(s1[i] != '\0' && s1[i] == s2[i] && s2[i] != '\0')
    {
        i++;
    }
    return(s1[i] - s2[i]); 
}

void ft_putstr(char *str)
{
    unsigned int i = 0; 

    while(str[i] != '\0')
    {
        write(1, &str[i], 1); 
        i++; 
    }
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

char *ft_strcpy(char *dest, char *src)
{
    int i = 0; 

    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(dest); 
}

int ft_strlen(char *str)
{
    int i = 0; 
    while(str[i])
        i++;
    return(i);
}