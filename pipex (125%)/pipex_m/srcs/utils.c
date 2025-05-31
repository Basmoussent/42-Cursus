/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:45:01 by bdenfir           #+#    #+#             */
/*   Updated: 2024/12/03 13:36:02 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	create_pipe(t_pipex *data)
{
	if (pipe(data->pipe_fd) == -1)
		error_exit("failed to create pipe", data);
}

void	wait_pid(pid_t pid1, pid_t pid2)
{
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	clean_data(t_pipex *data)
{
	if (data)
	{
		if (data->pipe_fd[0] != -1)
			close(data->pipe_fd[0]);
		if (data->pipe_fd[1] != -1)
			close(data->pipe_fd[1]);
		if (data->infile != -1)
			close(data->infile);
		if (data->outfile != -1)
			close(data->outfile);
	}
}

void	error_exit(char *str, t_pipex *data)
{
	clean_data(data);
	if (data)
		free(data);
	perror(str);
	exit(EXIT_FAILURE);
}

void	execute_child(t_pipex *data, char *cmd, char **args, char **envp)
{
	if (!cmd)
	{
		free_args(args);
		error_exit("Command not found", data);
	}
	pipe_redirection(data->current_cmd, data);
	if (execve(cmd, args, envp) == -1)
	{
		free_args(args);
		free(cmd);
		error_exit("command not found", data);
	}
}
