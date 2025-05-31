/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:23 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/17 12:26:46 by akassous         ###   ########.fr       */
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
