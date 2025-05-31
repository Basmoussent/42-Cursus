/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:16 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/17 12:27:37 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Ft_atoi mimic the behavior of the real atoi function.

It is used to convert ascii charater to intergers, and removes excess
characters that are not digits.

Error while processing the numbers will return 0;

ex ; -42born2code -> -42
ex : ThisWillReturn0 -> 0
*/

int	ft_atoi(const char *str)
{
	int	i;
	int	min;
	int	rslt;

	i = 0;
	min = 1;
	rslt = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			min = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		rslt *= 10;
		rslt += str[i++] - '0';
	}
	return (rslt * min);
}
