/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:04:35 by bdenfir           #+#    #+#             */
/*   Updated: 2024/12/09 15:20:59 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sb: Swap the first 2 elements at the top of stack b
void	sb(t_stack *b)
{
	int	temp;

	temp = b->data[b->top];
	if (b->top > 0)
	{
		b->data[b->top] = b->data[b->top - 1];
		b->data[b->top - 1] = temp;
		write(1, "sb\n", 1);
	}
}

// pb: Push top element of a to b
void	pb(t_stack *a, t_stack *b)
{
	if (!is_empty(a))
	{
		push(b, pop(a));
		write(1, "pb\n", 3);
	}
}

// rb: Rotate stack b upwards
void	rb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->top > 0)
	{
		temp = b->data[b->top];
		i = b->top;
		while (i > 0)
		{
			b->data[i] = b->data[i - 1];
			i--;
		}
		b->data[0] = temp;
		write(1, "rb\n", 3);
	}
}

// rrb: Reverse rotate stack b downwards
void	rrb(t_stack *b)
{
	int	temp;
	int	i;

	i = -1;
	temp = b->data[0];
	if (b->top > 0)
	{
		while (++i < b->top)
			b->data[i] = b->data[i + 1];
		b->data[b->top] = temp;
		write(1, "rrb\n", 4);
	}
}
