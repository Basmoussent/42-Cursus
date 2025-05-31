/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:26:05 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/01 10:38:28 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_input(void)
{
	char	*input;

	input = readline(COLOR_CYAN_BOLD "Minishell> " COLOR_RESET);
	if (!input)
	{
		ft_putstr_fd(COLOR_RED "exit\n" COLOR_RESET, 1);
		return (NULL);
	}
	return (input);
}

void	process_input(t_data *data)
{
	if (data->current_ast)
	{
		free_ast(data->current_ast);
		data->current_ast = NULL;
	}
	data->current_ast = lexing(data->input, data);
	if (data->current_ast)
		exec_ast(data->current_ast, data);
	reset_stream(data->original_stdin, data->original_stdout);
}

void	cleanup_current_iteration(t_data *data)
{
	if (data->input)
	{
		free(data->input);
		data->input = NULL;
	}
	if (data->hd_file)
	{
		unlink(data->hd_file);
		free(data->hd_file);
		data->hd_file = NULL;
	}
}
