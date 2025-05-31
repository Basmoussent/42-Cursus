/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:58:38 by bdenfir           #+#    #+#             */
/*   Updated: 2024/12/09 15:20:46 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa: Swap the first 2 elements at the top of stack a
void	sa(t_stack *a)
{
	int	temp;

	temp = a->data[a->top];
	if (a->top > 0)
	{
		a->data[a->top] = a->data[a->top - 1];
		a->data[a->top - 1] = temp;
		write(1, "sa\n", 3);
	}
}

// pa: Push top element of b to a
void	pa(t_stack *a, t_stack *b)
{
	if (!is_empty(b))
	{
		push(a, pop(b));
		write(1, "pa\n", 3);
	}
}

// ra: Rotate stack a upwards
void	ra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->top > 0)
	{
		temp = a->data[a->top];
		i = a->top;
		while (i > 0)
		{
			a->data[i] = a->data[i - 1];
			i--;
		}
		a->data[0] = temp;
		write(1, "ra\n", 3);
	}
}

// rra: Reverse rotate stack a downwards
void	rra(t_stack *a)
{
	int	temp;
	int	i;

	i = -1;
	temp = a->data[0];
	if (a->top > 0)
	{
		while (++i < a->top)
			a->data[i] = a->data[i + 1];
		a->data[a->top] = temp;
		write(1, "rra\n", 4);
	}
}
