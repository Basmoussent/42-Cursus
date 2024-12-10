/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   edge_case.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/09 18:23:44 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/12/09 18:28:10 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

// Sort 3 elements in stack a
void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bottom;

	top = a->data[a->top];
	mid = a->data[a->top - 1];
	bottom = a->data[a->top - 2];
	if (top > mid && mid > bottom)
	{
		sa(a);
		rra(a);
	}
	else if (top > bottom && bottom > mid)
		ra(a);
	else if (mid > top && top > bottom)
		rra(a);
	else if (mid > bottom && bottom > top)
	{	
		rra(a);
		sa(a);
	}
	else if (bottom > top && top > mid)
		sa(a);
}

// Find index of the smallest element in the stack
int	find_min_index(t_stack *a)
{
	int	min;
	int	min_index;
	int	i;

	min = a->data[a->top];
	min_index = a->top;
	i = a->top - 1;
	while (i >= 0)
	{
		if (a->data[i] < min)
		{
			min = a->data[i];
			min_index = i;
		}
		i--;
	}
	return (min_index);
}

// Push the smallest element to stack b
void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = find_min_index(a);
	while (a->top != min_index)
	{
		ra(a);
		min_index = find_min_index(a);
	}
	pb(a, b);
}

// Sort 4 elements
void	sort_four(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
}

// Sort 5 elements
void	sort_five(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
