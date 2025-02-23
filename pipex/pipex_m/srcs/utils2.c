/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils2.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/04 16:40:33 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/11/30 17:05:40 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*check_path(char *path_prefix, char *cmd)
{
	char	*path;
	char	*full_path;

	path = ft_strjoin(path_prefix, "/");
	if (!path)
		return (NULL);
	full_path = ft_strjoin(path, cmd);
	free(path);
	if (full_path && access(full_path, F_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

char	*find_executable(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths || !*paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path = check_path(paths[i], cmd);
		if (path)
		{
			free_args(paths);
			return (path);
		}
		i++;
	}
	free_args(paths);
	return (NULL);
}

void pipe_redirection(int nb_cmd, t_pipex *data)
{
    if (nb_cmd == 1)
    {
        dup2(data->infile, STDIN_FILENO);
        dup2(data->pipe_fd[1], STDOUT_FILENO);
    }
    else if (nb_cmd == data->total_cmds)
    {
        dup2(data->pipe_fd[0], STDIN_FILENO);
        dup2(data->outfile, STDOUT_FILENO);
    }
    else
    {
        dup2(data->pipe_fd[0], STDIN_FILENO);
        dup2(data->pipe_fd[1], STDOUT_FILENO);
        close(data->pipe_fd[0]);
        close(data->pipe_fd[1]);
    }
	close(data->pipe_fd[0]);
    close(data->pipe_fd[1]);
}
