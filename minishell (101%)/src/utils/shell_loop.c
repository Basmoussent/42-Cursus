/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:26:05 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/01 09:33:41 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_loop(t_data *data)
{
	while (1)
	{
		signal(SIGINT, handle_signals);
		signal(SIGQUIT, SIG_IGN);
		data->original_stdin = dup(STDIN_FILENO);
		data->original_stdout = dup(STDOUT_FILENO);
		data->input = read_input();
		if (!data->input)
			break ;
		if (data->input[0] != '\0')
			add_history(data->input);
		process_input(data);
		cleanup_current_iteration(data);
	}
}
