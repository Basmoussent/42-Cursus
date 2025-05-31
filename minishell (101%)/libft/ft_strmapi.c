/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:14:00 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/17 12:18:59 by akassous         ###   ########.fr       */
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
