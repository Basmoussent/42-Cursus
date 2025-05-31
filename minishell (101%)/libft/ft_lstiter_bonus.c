/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:29:23 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/17 12:25:07 by akassous         ###   ########.fr       */
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
