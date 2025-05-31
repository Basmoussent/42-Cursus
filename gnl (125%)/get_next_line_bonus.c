/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:45:53 by bdenfir           #+#    #+#             */
/*   Updated: 2025/05/31 19:17:06 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_file(int fd, char *resultat)
{
	char	*temp_buff;
	char	*new_resultat;
	int		bytes;

	if (!resultat)
		resultat = ft_calloc(1, 1);
	temp_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_buff)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, temp_buff, BUFFER_SIZE);
		if (bytes < 0)
			return (clear(temp_buff, resultat));
		temp_buff[bytes] = '\0';
		new_resultat = ft_strjoin(resultat, temp_buff);
		free(resultat);
		resultat = new_resultat;
		if (ft_strchr(resultat, '\n'))
			break ;
	}
	free(temp_buff);
	return (resultat);
}

static char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + (buffer[i] == '\n') + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*get_next(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!new_buffer)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = get_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	buffer[fd] = get_next(buffer[fd]);
	return (line);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;

// 	if (argc != 2)
// 	{
// 		printf("Usage: %s <filename>\n", argv[0]);
// 		return (1);
// 	}

// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Error opening file\n");
// 		return (1);
// 	}

// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }