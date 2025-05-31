/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:59:25 by bdenfir           #+#    #+#             */
/*   Updated: 2024/09/27 22:54:35 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*rslt;
	t_list	*new_node;

	rslt = 0;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&rslt, del);
			return (0);
		}
		if (!rslt)
			rslt = new_node;
		else
		{
			tmp = ft_lstlast(rslt);
			tmp->next = new_node;
		}
		lst = lst->next;
	}
	return (rslt);
}
