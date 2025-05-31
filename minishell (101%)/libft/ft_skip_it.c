/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:18:48 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/17 12:13:16 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skipt_it(char *str, int c)
{
	int	i;
	int	len;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	while (i <= len && str[i] != c)
		i++;
	while (i <= len && str[i] == c)
		i++;
	if (str[i] == '\0')
		return (str);
	return (&str[i]);
}
