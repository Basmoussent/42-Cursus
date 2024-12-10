/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:54:08 by bdenfir           #+#    #+#             */
/*   Updated: 2024/12/10 13:30:35 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_argument(const char *ar)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		if (!ft_isdigit(ar[i]) && !(ar[i] == '-' && i == 0) && (ar[i] != ' '))
			return (0);
		i++;
	}
	return (1);
}

int	validate_uniqueness(long *parsed, int count)
{
	int		i;
	int		j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (i != j && parsed[i] == parsed[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	error_exit(void)
{
	write(2, "error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_all(long *elements, t_stack *a, t_stack *b)
{
	if (elements)
		free(elements);
	if (a)
	{
		if (a->data)
			free(a->data);
		free(a);
	}
	if (b)
	{
		if (b->data)
			free(b->data);
		free(b);
	}
}
