/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:45:52 by bdenfir           #+#    #+#             */
/*   Updated: 2025/05/31 19:17:11 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ptr)
		return (NULL);
	while (*s1)
	{
		ptr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		ptr[i] = *s2;
		i++;
		s2++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*new;
	size_t		i;

	if (size != 0 && nmemb > ((size_t) - 1 / size))
		return (0);
	new = (void *) malloc(size * nmemb);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		*(unsigned char *)(new + i) = 0;
		i++;
	}
	return (new);
}

char	*clear(char *buffer, char *buf)
{
	free(buffer);
	free(buf);
	return (NULL);
}
