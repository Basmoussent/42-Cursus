/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strtrim.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/26 19:14:07 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/11/16 10:57:04 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

/*
The strtrim function will eliminate every
occurence of any character in the set from s1.
*/

static int	ft_char_in_strn(char c, char const *strn)
{
	size_t	i;

	i = 0;
	while (strn[i])
	{
		if (strn[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strn;
	size_t	i;
	size_t	begin;
	size_t	finish;

	begin = 0;
	while (s1[begin] && ft_char_in_strn(s1[begin], set))
		begin++;
	finish = ft_strlen(s1);
	while (finish > begin && ft_char_in_strn(s1[finish - 1], set))
	{
		finish--;
	}
	strn = (char *)malloc(sizeof(*s1) * (finish - begin + 1));
	if (!strn)
		return (NULL);
	i = 0;
	while (begin < finish)
	{
		strn[i++] = s1[begin++];
	}
	strn[i] = 0;
	return (strn);
}
