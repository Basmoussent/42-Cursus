/* ************************************************************************** */
/*									  */
/*							:::	 ::::::::   */
/*   ft_skip.c					  :+:   :+:	:+:   */
/*						  +:+ +:+	   +:+	*/
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	 */
/*   Created: 2025/03/04 08:27:42 by bdenfir		   #+#  #+#		  */
/*   Updated: 2025/03/06 14:29:07 by bdenfir		  ###   ########.fr	*/
/*									  */
/* ************************************************************************** */

#include "libft.h"

bool	is_in_charset(char c, const char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (true);
		charset++;
	}
	return (false);
}

char	*ft_skip(char *str, const char *charset)
{
	int	i;

	i = 0;
	while (str[i] && is_in_charset(str[i], charset))
		i++;
	return (&str[i]);
}
