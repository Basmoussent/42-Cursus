/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils2.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/04 16:40:33 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/10/05 15:52:14 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "pipex.h"

char	*find_executable(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	if (!paths || !*paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			free_args(paths);
			return (path);
		}
		free(path);
	}
	return (free_args(paths), NULL);
}

void	pipe_redirection(int nb_cmd, t_pipex *data)
{
	int	i;

	if (nb_cmd == 0)
	{
		dup2(data->infile, STDIN_FILENO);
		dup2(data->pipe_fd[0][1], STDOUT_FILENO);
	}
	else if (nb_cmd == data->pipe_count)
	{
		dup2(data->pipe_fd[nb_cmd - 1][0], STDIN_FILENO);
		dup2(data->outfile, STDOUT_FILENO);
	}
	else
	{
		dup2(data->pipe_fd[nb_cmd - 1][0], STDIN_FILENO);
		dup2(data->pipe_fd[nb_cmd][1], STDOUT_FILENO);
	}
	i = -1;
	while (++i < data->nb_cmd)
	{
		close(data->pipe_fd[i][0]);
		close(data->pipe_fd[i][1]);
	}
	close(data->infile);
	close(data->outfile);
}

void	handle_here_doc(char *limiter, t_pipex *data)
{
	char	*line;
	int		here_doc_pipe[2];

	if (pipe(here_doc_pipe) < 0)
		error_exit("Failed to create here_doc pipe", data, NULL, 1);
	while (1)
	{
		write(STDOUT_FILENO, "heredoc> ", 9);
		if (get_next_line(&line) <= 0)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(here_doc_pipe[1], line, ft_strlen(line));
		free(line);
	}
	close(here_doc_pipe[1]);
	data->infile = here_doc_pipe[0];
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	return (r);
}

void	free_pids(pid_t **pids, int count)
{
	int	i;

	i = 0;
	if (pids)
	{
		while (i < count)
		{
			if (pids[i] != NULL)
			{
				free(pids[i]);
				pids[i] = NULL;
			}
			i++;
		}
		free(pids);
		pids = NULL;
	}
}
