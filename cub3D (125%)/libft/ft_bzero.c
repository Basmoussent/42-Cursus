/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:18 by bdenfir           #+#    #+#             */
/*   Updated: 2024/11/06 14:00:17 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
bzero is a function that will set to 0 the next n_bytes 
starting from the adresse passed as a parameter.

ex : "ThisIsARandomMemoryAdress"
ex : 0000000000000000000000000

(it wont be display as shown in the example but 0 representes empty 
memory)
*/

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n)
	{
		*p++ = 0;
		--n;
	}
}
