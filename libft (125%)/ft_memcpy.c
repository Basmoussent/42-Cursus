/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:31 by bdenfir           #+#    #+#             */
/*   Updated: 2024/11/16 10:32:43 by bdenfir          ###   ########.fr       */
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
