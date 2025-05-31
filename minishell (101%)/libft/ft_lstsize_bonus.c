/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstsize.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/27 18:02:29 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/09/27 18:05:54 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

/*
Count the number of elements in the list.
*/

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
