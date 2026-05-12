/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novella <novella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:36:21 by novella           #+#    #+#             */
/*   Updated: 2026/03/31 23:07:43 by novella          ###   ########.fr       */
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

int read_line(char *buffer, int max_len)
{
    int i;
    char c;
    ssize_t bytes_read;

    if (!buffer || max_len <= 0)
        return (-1);
    i = 0;
    while (i < max_len - 1)
    {
        bytes_read = read(0, &c, 1);
        if (bytes_read <= 0)
        {
            if (i == 0)
                return ((int)bytes_read);
            break ;
        }
        if (c == '\n')
            break ;
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
    return (i);
}