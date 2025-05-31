/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_splitset.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/16 15:13:12 by bdenfir		   #+#	#+#			 */
/*   Updated: 2025/03/11 15:10:48 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c, int max_split)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			count++;
			if (max_split > 0 && count >= (size_t)max_split)
				return (count);
		}
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

static int	handle_max_split(char **rslt, const char *s, size_t j)
{
	rslt[j] = ft_strdup(&s[0]);
	rslt[j + 1] = NULL;
	return (0);
}

static int	fill_rslt(char **rslt, char const *s, char c, int max_split)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		while (s[i + count] && s[i + count] != c)
			count++;
		if (count > 0)
		{
			if (max_split > 0 && j >= (size_t)max_split)
				return (handle_max_split(rslt, &s[i], j));
			rslt[j] = ft_calloc(count + 1, sizeof(char));
			if (!rslt[j])
				return (1);
			fill_tab(rslt[j++], &s[i], c);
			i += count;
		}
		else
			i++;
	}
	return (rslt[j] = NULL, 0);
}

char	**ft_splitset(char const *s, char c, int max_split)
{
	size_t	words;
	char	**rslt;

	if (!s)
		return (NULL);
	words = count_words(s, c, max_split);
	rslt = ft_calloc(words + 3, sizeof(char *));
	if (!rslt)
		return (NULL);
	if (fill_rslt(rslt, s, c, max_split) == 1)
	{
		free_tab((void **)rslt);
		return (NULL);
	}
	return (rslt);
}
