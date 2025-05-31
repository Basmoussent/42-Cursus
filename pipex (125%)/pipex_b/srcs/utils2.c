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

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r > 0 && c != '\n' && c != '\0')
	{
		buffer[i++] = c;
		r = read(0, &c, 1);
	}
	if (r > 0)
		buffer[i++] = '\n';
	buffer[i] = '\0';
	*line = buffer;
	return (r);
}

int	open_file(char *filename, int flags, int mode)
{
	int	fd;

	fd = open(filename, flags, mode);
	if (fd < 0)
		error_exit("Error opening file", 1);
	return (fd);
}

void	process_cmds(int argc, char **argv, char **envp, int start)
{
	int	fd[2];
	int	stdin_fd;

	stdin_fd = STDIN_FILENO;
	while (start < argc - 2)
	{
		if (pipe(fd) == -1)
			error_exit("Error creating pipe", 1);
		child_process(argv[start], envp, stdin_fd, fd[1]);
		close(fd[1]);
		stdin_fd = fd[0];
		start++;
	}
	dup2(stdin_fd, STDIN_FILENO);
	close(stdin_fd);
}
