/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:41 by bdenfir           #+#    #+#             */
/*   Updated: 2024/12/25 23:13:35 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

/*
strchr will search for the first occurence of c in the s memory area
and return a pointer to it, Null will be returned if no occurence
is found.
*/

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	c = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
/*
#include <stdio.h>
int main(){

	char	str[] = "Eu vou encontrar um ponto . Ca esta ele!";
	char	c = '.';
	printf("%s", ft_strchr(str, c));
}
*/