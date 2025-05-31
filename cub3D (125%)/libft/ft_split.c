/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:13:12 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/11 15:41:07 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_tab(void **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

static size_t	count_words(char const *s, char c)
{
	size_t		count;
	size_t		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	fill_tab(char *tab, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
}

static int	fill_rslt(char **rslt, char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		count;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		while (s[i + count] && s[i + count] != c)
			count++;
		if (count > 0)
		{
			rslt[j] = malloc(sizeof(char) * (count + 1));
			if (!rslt[j])
				return (1);
			fill_tab(rslt[j++], &s[i], c);
			i += count;
		}
		else
			i++;
	}
	rslt[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t		words;
	char		**rslt;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	rslt = malloc(sizeof(char *) * (words + 1));
	if (!rslt)
		return (NULL);
	if (fill_rslt(rslt, s, c) == 1)
	{
		free_tab((void **)rslt);
		return (NULL);
	}
	return (rslt);
}
