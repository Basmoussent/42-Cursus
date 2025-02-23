/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstlast.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/27 18:07:31 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/09/27 22:54:11 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

/*
Returns the last elemet of the list.
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	return (ft_lstlast(lst->next));
}
