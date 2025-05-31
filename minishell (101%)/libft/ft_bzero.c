/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:18 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/17 12:27:16 by akassous         ###   ########.fr       */
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
