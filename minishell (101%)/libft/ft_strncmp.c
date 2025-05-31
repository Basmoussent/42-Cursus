/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strncmp.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/02 12:22:35 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/07/02 12:22:35 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

/*
strncmp will copare the first n bytes of s1/s2
and will return the difference between the first mismatch,
 or 0 if they are the same,
*/

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n < 1)
	{
		return (0);
	}
	while ((*s1 == *s2 && *s1 && *s2) && i < n - 1)
	{
		s1++;
		s2++;
		i++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
