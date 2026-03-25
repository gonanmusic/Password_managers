/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_credential.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novella <novella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:36:31 by novella           #+#    #+#             */
/*   Updated: 2026/03/17 16:36:32 by novella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "basic_function.h"
void free_credential(struct credential *my_credential)
{
    free(my_credential->site);
    free(my_credential->id);
    free(my_credential->password);
    free(my_credential); 
}