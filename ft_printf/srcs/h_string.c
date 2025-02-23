/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:16:31 by bdenfir           #+#    #+#             */
/*   Updated: 2024/11/22 04:01:41 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	handle_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	handle_char(int c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	const char		*s;	
	const size_t	*w;
	size_t			high_bit_mask;
	size_t			low_bit_mask;
	size_t			word;

	high_bit_mask = 0x8080808080808080ULL;
	low_bit_mask = 0x0101010101010101ULL;
	s = str;
	w = (const size_t *)s;
	while ((uintptr_t)s % sizeof(size_t) != 0)
		if (*s++ == '\0')
			return (s - str);
	while (1)
	{
		word = *w;
		if (((word - low_bit_mask) & ~word & high_bit_mask) != 0)
			break ;
		w++;
	}
	s = (const char *)w;
	while (*s != '\0')
		s++;
	return (s - str);
}

void	ft_putstr_fd(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}
