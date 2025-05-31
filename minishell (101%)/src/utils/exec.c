/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:21:27 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/01 09:17:41 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*generate_unique_filename(void)
{
	int		count;
	char	*num;
	char	*filename;
	char	*tmp;

	count = 1;
	filename = ft_strdup(HERE_DOC_TMP);
	while (access(filename, F_OK) == 0)
	{
		num = ft_itoa(count++);
		tmp = filename;
		filename = ft_strjoin(HERE_DOC_TMP, "_");
		free(tmp);
		tmp = filename;
		filename = ft_strjoin(tmp, num);
		free(tmp);
		free(num);
	}
	return (filename);
}

static int	should_expand_vars(char *delimiter)
{
	char	*processed;
	int		expand;

	processed = ft_strdup(delimiter);
	ft_process_input(delimiter, processed);
	expand = (ft_strncmp(delimiter, processed, ft_strlen(delimiter)) == 0);
	free(processed);
	return (expand);
}

void	process_heredoc_line(char *line, int fd, t_data *data, int expand)
{
	char	*expanded_line;

	if (expand)
		expanded_line = expand_all_variables(line, data);
	else
		expanded_line = ft_strdup(line);
	write(fd, expanded_line, ft_strlen(expanded_line));
	write(fd, "\n", 1);
	free(expanded_line);
	free(line);
}

int	handle_heredoc_input(int fd, char *delimiter, t_data *data,
	int should_expand)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		process_heredoc_line(line, fd, data, should_expand);
	}
	return (fd);
}

int	heredoc_logic(char *delimiter, t_data *data)
{
	int		fd;
	char	*new_delimiter;
	int		should_expand;

	new_delimiter = ft_strdup(delimiter);
	ft_process_input(delimiter, new_delimiter);
	should_expand = should_expand_vars(delimiter);
	data->hd_file = generate_unique_filename();
	fd = open(data->hd_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		free(data->hd_file);
		free(new_delimiter);
		return (-1);
	}
	fd = handle_heredoc_input(fd, new_delimiter, data, should_expand);
	close(fd);
	free(new_delimiter);
	fd = open(data->hd_file, O_RDONLY);
	return (fd);
}
