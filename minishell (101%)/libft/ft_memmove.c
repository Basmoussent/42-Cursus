/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:48:54 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/17 12:23:04 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The memmove function is used to copy the first n bytes of th
src memory area to the dst memory area.

In this function, we cast both src and dst to (unsigned char *).
The reason for this cast is that void * is a generic pointer type and
doesn’t specify a data type. By casting to (unsigned char *), we ensure
that both src and dst are treated as byte-level pointers. This allows us
to copy the data one byte at a time, ensuring precise control over each memory
 location.
Additionally, casting to (unsigned char *) allows us to increment the pointer
by exactly 1 byte for each iteration, as sizeof(unsigned char) == 1.
This ensures that we correctly copy each byte in sequence, regardless of the
original data type of src and dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if ((dst == src) || n == 0)
		return (dst);
	if (dst > src)
	{
		i = n - 1;
		while (i > 0)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i--;
		}
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i--;
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	return (dst);
}
