/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   parsing.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/11 18:28:11 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/12/11 18:28:40 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "struct.h"

static void	validate_first_line(char *line, t_info *map, int fd)
{
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	map->cols = ft_strlen(line);
	if (occur(line, '1') != map->cols)
	{
		free(line);
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			free(line);
		}
		close(fd);
		error_exit("Error on first line\n");
	}
}

static void	validate_row(char *line, t_info *map, char **array, int fd)
{
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	if (ft_strlen(line) != (size_t)map->cols || line[0] != '1'
		|| line[map->cols - 1] != '1')
	{	
		free(line);
		free_map(array, map->rows, line, fd);
		error_exit("Boundary error");
	}
	map->player_count += occur(line, 'P');
	map->exit_count += occur(line, 'E');
	map->collectible_count += occur(line, 'C');
}

static char	**store_line(char **map_array, char *line, int row, int fd)
{
	static int	current_size = 0;
	int			new_size;

	if (current_size == 0 || row >= current_size)
	{
		new_size = current_size + 10;
		map_array = ft_realloc(map_array,
				sizeof(char *) * current_size,
				sizeof(char *) * new_size);
		if (!map_array)
		{
			free(line);
			free_map(map_array, row, line, fd);
			error_exit("Error allocating space");
		}
		current_size = new_size;
	}
	map_array[row] = line;
	return (map_array);
}

static void	validate_last_line(char *line, t_info *map, char **array, int fd)
{
	if (occur(line, '1') != map->cols)
		error_exit("Error\n");
	if (map->player_count != 1 || map->exit_count != 1
		|| map->collectible_count < 1)
	{	
		free(line);
		free_map(array, map->rows, line, fd);
		error_exit("Error on last line\n");
	}
}

char	**read_map(char *name, t_info *map)
{
	int		fd;
	char	*line;
	char	**map_array;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		error_exit("error opening map file\n");
	map_array = NULL;
	line = get_next_line(fd);
	if (line)
		validate_first_line(line, map, fd);
	while (line)
	{
		validate_row(line, map, map_array, fd);
		map_array = store_line(map_array, line, map->rows++, fd);
		line = get_next_line(fd);
		if (!line)
			validate_last_line(map_array[map->rows - 1], map, map_array, fd);
	}
	return (close(fd), map_array);
}
