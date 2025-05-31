/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:31 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/17 12:23:24 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
the memcpy funciton will copy the content related to the
 src pointer, to memory boc pointed by dest,
it will only copy the first n bytes of src.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long int	i;
	char				*strd;
	char				*srcd;

	if (!dest && !src)
		return (NULL);
	strd = (char *)dest;
	srcd = (char *)src;
	i = -1;
	while (++i < n)
		strd[i] = srcd[i];
	return (dest);
}
