/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:30:58 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/17 12:25:37 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates (with malloc(3)) and returns a new
element. The member variable 'content' is
initialized using the parameter value
'content'. The 'next' variable is initialized to
NULL
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (*lst)
	{
		node = ft_lstlast(*lst);
		if (node)
			node->next = new;
		else
			*lst = new;
	}
	else
		*lst = new;
}
