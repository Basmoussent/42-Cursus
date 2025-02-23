/* ************************************************************************** */
/*									  */
/*							:::	 ::::::::   */
/*   pipex.c											:+:   :+:	:+:   */
/*						  +:+ +:+	   +:+	*/
/*   By: bdenfir <bdenfir@student.42.fr>			+#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	 */
/*   Created: 2024/10/04 16:10:26 by bdenfir		   #+#  #+#		  */
/*   Updated: 2024/11/27 22:14:31 by bdenfir		  ###   ########.fr	*/
/*									  */
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

t_pipex	*init_data(char *f1, char *f2, int nb_cmd, int hd)
{
	t_pipex	*data;
	int		i;

	data = ft_calloc(1, sizeof(t_pipex));
	if (!data)
		error_exit("memory allocation failed", NULL, NULL, 1);
	data->nb_cmd = nb_cmd;
	i = -1;
	while (++i < nb_cmd)
	{
		data->pipe_fd[i][0] = -1;
		data->pipe_fd[i][1] = -1;
	}
	data->pipe_count = nb_cmd - 1;
	if (!hd)
	{
		data->infile = open(f1, O_RDONLY);
		data->outfile = open(f2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else
		data->outfile = open(f2, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if ((!hd && data->infile < 0) || data->outfile < 0)
		error_exit("Error opening files", data, NULL, 1);
	return (data);
}
// CHANGE CA (argv[1][0] == 'h')(argv[1][0] == 'h')(argv[1][0] == 'h')

pid_t	*fork_child(t_pipex *data, char **argv, char **envp, int nb_cmd)
{
	pid_t	*pid;
	char	*cmd;
	char	**args;

	pid = ft_calloc(1,sizeof(pid_t));
	if (!pid)
		error_exit("Error creating fork/child process", data, NULL, 1);
	args = ft_split(argv[(nb_cmd + 2) + (argv[1][0] == 'h')], ' ');
	cmd = NULL;
	if (args)
		cmd = find_executable(args[0], envp);
	*pid = fork();
	if (*pid < 0)
		error_exit("Error creating fork/child process", data, pid, 1);
	if (*pid == 0)
	{
		pipe_redirection(nb_cmd, data);
		if (!cmd)
		{
			free_args(args);
			error_exit("Error: command not found", data, pid, 127);
		}
		execve(cmd, args, envp);
	}
	return (ft_norme(args, cmd, pid));
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;
	pid_t	**pids;
	int		i;
	int		hd;

	hd = (argc > 1 && ft_strncmp(argv[1], "here_doc", 8) == 0);
	if ((!hd && argc < 5) || (hd && argc < 6))
		error_exit("Usage: ./pipex file1 cmd1 cmd2 cmdn file2", NULL, NULL, 1);
	pids = ft_calloc((argc - (3 - hd)), sizeof(pid_t *) * (argc - (3 - hd)));
	if (!pids)
		error_exit("Memory allocation for pids array failed", NULL, NULL, 1);
	if (!envp || !*envp)
		error_exit("Environment variable is NULL", NULL, NULL, 1);
	data = init_data(argv[1], argv[argc - 1], argc - (3 + hd), hd);
	data->pids = pids;
	if (hd)
		handle_here_doc(argv[2], data);
	create_pipe(data);
	i = -1;
	while (++i < argc - (3 + hd))
		pids[i] = fork_child(data, argv, envp, i);
	clean_data(data);
	wait_pid(pids, argc - (3 + hd));
	free_pids(pids, argc - (3 + hd));
	return (free(data), 0);
}
