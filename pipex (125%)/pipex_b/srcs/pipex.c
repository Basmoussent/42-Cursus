/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:26:07 by bdenfir           #+#    #+#             */
/*   Updated: 2024/12/04 16:52:18 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	execute(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	cmd_path = NULL;
	if (!args || !args[0])
	{
		free_args(args);
		error_exit("Error: Command not found", 127);
	}
	if (ft_strchr(args[0], '/') != NULL)
	{
		execve(args[0], args, envp);
		free_args(args);
		error_exit("Error executing command", 126);
	}
	cmd_path = find_executable(args[0], envp);
	if (!cmd_path)
	{
		free_args(args);
		error_exit("Error: Command not found", 127);
	}
	execve(cmd_path, args, envp);
	ft_norme(args, cmd_path, 127);
}

void	child_process(char *argv, char **envp, int pipe_in, int pipe_out)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit("Error creating child process", 1);
	if (pid == 0)
	{
		if (pipe_in != STDIN_FILENO)
		{
			dup2(pipe_in, STDIN_FILENO);
			close(pipe_in);
		}
		if (pipe_out != STDOUT_FILENO)
		{
			dup2(pipe_out, STDOUT_FILENO);
			close(pipe_out);
		}
		execute(argv, envp);
	}
	else
	{
		close(pipe_out);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limiter, int argc)
{
	pid_t	reader;
	int		fd[2];

	if (argc < 6)
		error_exit("Usage: ./pipex here_doc limiter cmd1 cmd2 _ cmdn file2", 1);
	if (pipe(fd) == -1)
		error_exit("pipe error", 1);
	reader = fork();
	if (reader == -1)
		error_exit("fork error", 1);
	if (reader == 0)
		handle_here_doc(fd, limiter);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	hd;
	int	fileout;
	int	start;

	if (argc < 5)
		error_exit("Usage: ./pipex file1 cmd1 cmd2 ... cmdn file2", 1);
	hd = ft_strncmp(argv[1], "here_doc", 8) == 0;
	if (hd)
	{
		here_doc(argv[2], argc);
		start = 3;
		fileout = open_file(argv[argc - 1], 01 | 0100 | 02000, 0644);
	}
	else
	{
		start = 2;
		dup2(open_file(argv[1], O_RDONLY, 0), STDIN_FILENO);
		fileout = open_file(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	process_cmds(argc, argv, envp, start);
	dup2(fileout, STDOUT_FILENO);
	close(fileout);
	execute(argv[argc - 2], envp);
	return (0);
}
