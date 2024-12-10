/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:06:35 by bdenfir           #+#    #+#             */
/*   Updated: 2024/12/10 13:28:16 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = (int *)malloc(sizeof(int) * capacity);
	if (!stack->data)
	{
		free(stack);
		return (NULL);
	}
	stack->top = -1;
	stack->capacity = capacity;
	return (stack);
}

// Push element onto stack
void	push(t_stack *stack, int value)
{
	if (stack->top < stack->capacity - 1)
		stack->data[++stack->top] = value;
}

// Pop element from stack
int	pop(t_stack *stack)
{
	if (stack->top >= 0)
		return (stack->data[stack->top--]);
	return (-1);
}

// Peek top element of stack
int	peek(t_stack *stack)
{
	if (stack->top >= 0)
		return (stack->data[stack->top]);
	return (-1);
}

// Check if stack is empty
int	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}
