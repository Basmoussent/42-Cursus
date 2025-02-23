/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_numbers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:14:12 by bdenfir           #+#    #+#             */
/*   Updated: 2024/11/22 04:01:02 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	handle_integer(int c)
{
	ft_putnbr_fd(c);
	return (int_length(c));
}

int	handle_unsigned(unsigned int value)
{
	char	*c;
	int		length;

	c = ft_utoa(value);
	ft_putstr_fd(c);
	length = (int)ft_strlen(c);
	free(c);
	return (length);
}

int	int_length(int n)
{
	if (n == INT_MIN)
	{
		return (11);
	}
	if (n > -10 && n < 0)
		return (2);
	if (n < 0)
	{
		return (2 + int_length(-n / 10));
	}
	if (n < 10)
	{
		return (1);
	}
	return (1 + int_length(n / 10));
}

void	ft_putnbr_fd(int nb)
{
	unsigned int	n;
	unsigned char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr_fd(n / 10);
		ft_putnbr_fd(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}
