/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:45:47 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/01 10:35:19 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_child(t_ast_node *node, t_data *data, int *pipe_fds)
{
	close(pipe_fds[0]);
	dup2(pipe_fds[1], STDOUT_FILENO);
	close(pipe_fds[1]);
	exec_ast(node->left, data);
	exit(data->status);
}

void	handle_right_child(t_ast_node *node, t_data *data, int *pipe_fds)
{
	close(pipe_fds[1]);
	dup2(pipe_fds[0], STDIN_FILENO);
	close(pipe_fds[0]);
	exec_ast(node->right, data);
	exit(g_signal_received);
}

void	handle_pipe_parent(int *pipe_fds,
	pid_t left_pid, pid_t right_pid)
{
	int	status;

	close(pipe_fds[0]);
	close(pipe_fds[1]);
	signal(SIGINT, handle_sigint_child);
	signal(SIGQUIT, SIG_IGN);
	waitpid(left_pid, NULL, 0);
	waitpid(right_pid, &status, 0);
	if (((status) & 0x7F) != 0)
	{
		if (((status) & 0x7F) == SIGQUIT)
			write(2, "Quit (Core dumped)\n", 19);
		g_signal_received = 128 + ((status) & 0x7F);
	}
	else if (((status) & 0x7F) == 0)
		g_signal_received = ((status) >> 8) & 0xFF;
}
