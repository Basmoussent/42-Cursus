/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:45:47 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/01 09:36:04 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_command(t_ast_node *node, t_data *data)
{
	pid_t	pid;
	char	**args;

	if (!node || !node->value)
		handle_error("Invalid command structure", 1);
	if (is_builtin(node))
	{
		g_signal_received = exec_builtin(node, data);
		return ;
	}
	args = prepare_args(node);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	pid = fork();
	if (pid == -1)
		handle_error("fork", 1);
	if (pid == 0)
		handle_command_child(node, data, args);
	handle_command_parent(pid, args);
}

static void	execute_pipe(t_ast_node *node, t_data *data)
{
	int		pipe_fds[2];
	pid_t	left_pid;
	pid_t	right_pid;

	if (!node || !node->left || !node->right)
	{
		write(2, "Invalid pipe structure\n", 23);
		cleanup_and_exit(node, data, NULL, NULL);
	}
	if (pipe(pipe_fds) == -1)
		handle_error("pipe", 1);
	left_pid = fork();
	if (left_pid == -1)
		handle_error("fork", 1);
	if (left_pid == 0)
		execute_child(node, data, pipe_fds);
	right_pid = fork();
	if (right_pid == -1)
		handle_error("fork", 1);
	if (right_pid == 0)
		handle_right_child(node, data, pipe_fds);
	handle_pipe_parent(pipe_fds, left_pid, right_pid);
}

void	exec_ast(t_ast_node *node, t_data *data)
{
	if (!node || !data)
		return ;
	if (node->type == PIPE)
		execute_pipe(node, data);
	else if (node->type == TRUNCATE || node->type == APPEND
		|| node->type == REDIRECT_INPUT || node->type == HEREDOC)
	{
		if (handle_redirection(node, data) == -1)
			return ;
		exec_ast(node->left, data);
	}
	else
		execute_command(node, data);
}
