/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:20 by bdenfir           #+#    #+#             */
/*   Updated: 2024/11/06 14:05:15 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
isalnum verify if a character is alpha-numeric,
which means if he is either in the alphabet or digits.
	
*/

int	ft_isalnum(int str)
{
	if (ft_isalpha(str) || ft_isdigit(str))
		return (1);
	return (0);
}
