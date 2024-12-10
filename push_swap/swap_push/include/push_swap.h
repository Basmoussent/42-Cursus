/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:25:10 by bdenfir           #+#    #+#             */
/*   Updated: 2024/12/10 13:28:19 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <../libft/libft.h>

typedef struct t_stack {
	int	*data;
	int	top;
	int	capacity;
}		t_stack;

void	sa(t_stack *a);
void	pa(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rra(t_stack *a);

void	sb(t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rb(t_stack *b);
void	rrb(t_stack *b);

int		parse_value(char *arg, long *parsed, int *count);
int		process_arg(char **arg_ptr, long *parsed, int *count);
int		process_argv(char *arg, long *parsed, int *count);
void	copy_elements(long *parsed, long **elements, int count);
int		parse_arguments(int argc, char *argv[], long **elements);
int		validate_arguments(int argc, char *argv[]);
int		is_valid_argument(const char *arg);
int		validate_uniqueness(long *parsed, int count);

t_stack	*init_stack(int capacity);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
int		peek(t_stack *stack);
int		is_empty(t_stack *stack);

void	normalize_elements(long *elements, int size);

void	free_all(long *elements, t_stack *a, t_stack *b);
void	error_exit(void);

void	sort_it(t_stack *a, t_stack *b, long *elements, int size);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);

#endif