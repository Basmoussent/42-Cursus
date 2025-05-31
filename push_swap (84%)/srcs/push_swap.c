/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push_swap.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/09 13:08:38 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/12/09 13:30:45 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

// Function to perform radix sort using the given operations
void	radix_sort(t_stack *a, t_stack *b, int max_bits)
{
	int	size;
	int	bit;
	int	i;
	int	num;

	size = a->top + 1;
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			num = peek(a);
			if (((num >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (!is_empty(b))
			pa(a, b);
		bit++;
	}
}

int	push_get_bit(long *elements, t_stack *stack, int size)
{
	int	i;
	int	max;
	int	bit;

	i = size;
	max = elements[0];
	while (--i >= 0)
	{
		if (elements[i] > max)
			max = elements[i];
		push(stack, elements[i]);
	}
	bit = 0;
	while (max > 0)
	{
		bit++;
		max >>= 1;
	}
	return (bit);
}

void	sort_it(t_stack *a, t_stack *b, long *elements, int size)
{
	int	max;

	max = push_get_bit(elements, a, size);
	if (is_sorted(a))
		return ;
	if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b, max);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->data[i] < stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	long int	*elements;
	int			size;
	t_stack		*a;
	t_stack		*b;

	size = parse_arguments(argc, argv, &elements);
	if (check_uniqueness(elements, size) < 0 || check_range(elements, size) < 0)
	{
		free(elements);
		error_exit();
	}
	normalize_elements(elements, size);
	a = init_stack(size);
	b = init_stack(size);
	if (!a || !b)
	{	
		free_all(elements, a, b);
		error_exit();
	}
	sort_it(a, b, elements, size);
	free_all(elements, a, b);
	return (0);
}
