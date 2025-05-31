/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:29:23 by bdenfir           #+#    #+#             */
/*   Updated: 2024/11/16 10:32:14 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
go to the list 'lst' and apply the function
'f' to the content of each element.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	node = lst;
	if (!lst || !f)
		return ;
	while (node->next != NULL)
	{
		f(node->content);
		node = node->next;
	}
	f(node->content);
}
