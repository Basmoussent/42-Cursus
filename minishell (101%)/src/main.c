/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:26:05 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/26 14:42:39 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile int	g_signal_received = 0;

static void	init_shell(t_data *data, char **envp)
{
	data->envp = copy_envp(envp);
	data->export = copy_export_list(envp);
	data->ast = 1;
	data->current_ast = NULL;
	data->tokens = NULL;
	data->input = NULL;
	data->hd_file = NULL;
	data->status = g_signal_received;
	data->saved_stdin = -1;
	data->saved_stdout = -1;
	data->original_stdin = -1;
	data->original_stdout = -1;
	data->in_shell = 0;
	if (!data->envp || !data->export)
	{
		cleanup_shell(data);
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	init_shell(&data, envp);
	shell_loop(&data);
	cleanup_shell(&data);
	return (0);
}
