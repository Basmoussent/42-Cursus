/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:14:00 by bdenfir           #+#    #+#             */
/*   Updated: 2024/11/06 16:30:20 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
strmapi will pass every character of s into
the f function and return the result
of the concatenation of every result,
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret_str;
	int		i;

	if (!s || !f)
		return (NULL);
	ret_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret_str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ret_str[i] = f(i, s[i]);
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
