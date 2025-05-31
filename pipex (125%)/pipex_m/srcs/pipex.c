/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pipex.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/04 16:10:26 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/11/30 17:57:11 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/pipex.h"

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

t_pipex	*init_data(char *file1, char *file2)
{
	t_pipex	*data;

	data = ft_calloc(1, sizeof(t_pipex));
	if (!data)
		error_exit("Allocation failed for t_pipex structure", data);
	data->infile = open(file1, O_RDONLY);
	data->outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->infile < 0 || data->outfile < 0)
		error_exit("Error opening files", data);
	dup2(data->infile, STDIN_FILENO);
	return (data);
}

pid_t	fork_child(t_pipex *data, char **argv, char **envp, int nb_cmd)
{
	pid_t	pid;
	char	*cmd;
	char	**args;

	if (!*envp)
		error_exit("error retrieving environments PATH", data);
	args = ft_split(argv[1 + nb_cmd], ' ');
	if (args && args[0])
		cmd = find_executable(args[0], envp);
	else
		cmd = NULL;
	pid = fork();
	if (pid < 0)
		error_exit("Error creating fork/child process", data);
	if (pid == 0)
	{
		data->current_cmd = nb_cmd;
		execute_child(data, cmd, args, envp);
	}
	free_args(args);
	free(cmd);
	return (pid);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;
	pid_t	pid1;
	pid_t	pid2;

	data = NULL;
	if (argc != 5)
		error_exit("Invalid Usage:./pipex file1 cmd1 cmd2 file2", data);
	if (!envp)
		error_exit("Error while retrieving environment paths", data);
	data = init_data(argv[1], argv[argc - 1]);
	create_pipe(data);
	pid1 = fork_child(data, argv, envp, 1);
	pid2 = fork_child(data, argv, envp, 2);
	clean_data(data);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	free(data);
	return (0);
}
