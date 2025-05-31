/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:23 by bdenfir           #+#    #+#             */
/*   Updated: 2024/11/06 14:06:34 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
isascii checks if a character belongs to the ascii table

note : (extended ascii table isn't included)
*/

int	ft_isascii(int str)
{
	if (str >= 0 && str <= 127)
		return (1);
	return (0);
}
