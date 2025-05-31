/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   data.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/09 16:15:11 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/12/09 17:18:45 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

static	void	copy_elements2(long *source, long *destination, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		destination[i] = source[i];
		i++;
	}
}

void	bubble_sort(long *array, int size)
{
	int		i;
	int		j;
	long	temp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	replace_with_indices(long *elements, long *sorted, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (elements[i] == sorted[j])
			{
				elements[i] = j ;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	normalize_elements(long *elements, int size)
{
	long	*sorted;

	if (size <= 0)
		return ;
	sorted = malloc(sizeof(long) * size);
	if (!sorted)
	{
		free(elements);
		error_exit();
	}
	copy_elements2(elements, sorted, size);
	bubble_sort(sorted, size);
	replace_with_indices(elements, sorted, size);
	free(sorted);
}

int	validate_arguments(int argc, char *argv[])
{
	int			i;
	const char	*arg;

	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		while (*arg)
		{
			while (*arg == ' ')
				arg++;
			if (*arg && !is_valid_argument(arg))
				return (-1);
			while (*arg && *arg != ' ')
				arg++;
		}
		i++;
	}
	return (0);
}
