/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:43:39 by bdenfir           #+#    #+#             */
/*   Updated: 2024/09/30 15:55:01 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	get_length(unsigned int n, int sign)
{
	int	i;

	i = 1;
	if (sign == -1 && n != 0)
		i++;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*convert_str(unsigned int nbr, char *number, int sign, int length)
{
	number[length--] = '\0';
	while (nbr > 9)
	{
		number[length--] = nbr % 10 + '0';
		nbr /= 10;
	}
	number[length] = nbr + '0';
	if (sign == -1 && nbr != 0)
		number[0] = '-';
	return (number);
}

char	*ft_utoa(unsigned int n)
{
	int				length;
	int				sign;
	unsigned int	cpy;
	unsigned int	nbr;
	char			*number;

	sign = 1;
	nbr = n;
	cpy = nbr;
	length = get_length(cpy, sign);
	number = malloc (length + 1);
	if (!number)
		return (0);
	convert_str(nbr, number, sign, length);
	return (number);
}
