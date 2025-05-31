/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:45:35 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/11 15:40:36 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(char **array)
{
	int	i;

	if (!array || !*array)
		return (0);
	i = 0;
	while (array[i] && ft_strlen(array[i]) > (size_t)0)
		i++;
	return (i);
}
