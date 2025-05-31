/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:20 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/17 12:26:52 by akassous         ###   ########.fr       */
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
