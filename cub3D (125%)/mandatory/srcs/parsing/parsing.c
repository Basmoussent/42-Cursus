/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   parsing.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/04 08:06:41 by bdenfir		   #+#	#+#			 */
/*   Updated: 2025/03/05 10:52:10 by agozlan		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_hex(char **rgb, t_game *game, char *line)
{
	char	**rgb_values;
	int		r;
	int		g;
	int		b;

	rgb_values = ft_split(rgb[1], ',');
	if (!rgb_values)
	{
		free_tab((void **)rgb);
		free(line);
		print_error("Malloc failed for rgb_values\n");
		free_all(game, 1);
	}
	if (ft_size(rgb_values) != 3)
	{
		free(line);
		free_tab((void **)rgb);
		free_tab((void **)rgb_values);
		print_error("rgb is NOT formated properly\n");
		free_all(game, 1);
	}
	r = ft_atoi(rgb_values[0]);
	g = ft_atoi(rgb_values[1]);
	b = ft_atoi(rgb_values[2]);
	return (free_tab((void **)rgb_values), r << 16 | g << 8 | b);
}

static void	check_remaining_lines(t_game *g, char *line)
{
	char	*next_line;

	next_line = get_next_line(g->tex->fd);
	while (next_line)
	{
		if (ft_strlen(next_line) > 1 || next_line[0] != '\n')
		{
			free(line);
			free(next_line);
			print_error("Invalid content after map\n");
			free_all(g, 1);
		}
		free(next_line);
		next_line = get_next_line(g->tex->fd);
	}
}

static void	process_map_line(t_game *g, char *line, int *end, int *map_started)
{
	if (ft_strlen(line) > 1 || line[0] != '\n')
	{
		*map_started = 1;
		extract_line(g, line, end);
	}
	else if (*map_started && line[0] == '\n')
		check_remaining_lines(g, line);
}

static void	parse_textures(t_game *g, char **line)
{
	while (*line && g->tex->loaded != 1)
	{
		extract_texture(g, *line);
		free(*line);
		*line = get_next_line(g->tex->fd);
	}
}

void	parsing(t_game *g)
{
	char	*line;
	int		end;
	int		map_started;

	map_started = 0;
	line = get_next_line(g->tex->fd);
	parse_textures(g, &line);
	while (line)
	{
		process_map_line(g, line, &end, &map_started);
		free(line);
		line = get_next_line(g->tex->fd);
	}
	if (g->tex->loaded != 1 || map_started == 0 || g->p->dir_x == -2)
	{
		print_error("One of the caracteristic did NOT load properly.\n");
		free_all(g, 1);
	}
	check_surrounded_by_walls(g);
}
