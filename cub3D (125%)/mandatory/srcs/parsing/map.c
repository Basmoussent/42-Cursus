/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   map.c											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/04 09:15:05 by bdenfir		   #+#	#+#			 */
/*   Updated: 2025/03/06 16:23:05 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

void	add_line_to_map(t_game *g, char *line, int i)
{
	char	**new_map;
	char	*new_line;

	new_line = ft_strdup(line);
	if (!new_line)
	{
		free(line);
		print_error("Malloc fail\n");
		free_all(g, 1);
	}
	new_map = (char **)ft_realloc(g->map, sizeof(char *) * (i + 1),
			sizeof(char *) * (i + 2));
	if (!new_map)
	{
		free(line);
		print_error("Malloc fail\n");
		free_all(g, 1);
	}
	g->map = new_map;
	g->map[i] = new_line;
	g->map[i + 1] = NULL;
}

void	check_case(t_game *g, char *line)
{
	int	y;

	y = 0;
	while (line[y])
	{
		if (!(line[y] == '0' || line[y] == '1' || line[y] == 'N'
				|| line[y] == 'S' || line[y] == 'E' || line[y] == 'W'
				|| line[y] == ' ' || line[y] == 'D'))
		{
			free(line);
			print_error("Unknown character encountered\n");
			free_all(g, 1);
		}
		if ((line[y] == 'N' || line[y] == 'S'
				|| line[y] == 'E' || line[y] == 'W'))
			init_player(line[y], g, line, y);
		y++;
	}
}

void	extract_line(t_game *g, char *line, int *end)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	if (len == 1 && line[0] == '\n')
		return ;
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	end++;
	if (g->map == NULL)
	{
		init_map(g, line);
		return ;
	}
	else
	{
		while (g->map[i] != NULL)
			i++;
		add_line_to_map(g, line, i);
	}
	check_case(g, line);
}

void	init_map(t_game *g, char *line)
{
	char	*new_line;

	new_line = ft_strdup(line);
	if (!new_line)
	{
		free(line);
		print_error("Malloc fail\n");
		free_all(g, 1);
	}
	g->map = (char **)ft_calloc(2, sizeof(char *));
	if (!g->map)
	{
		free(line);
		free(new_line);
		print_error("Malloc fail\n");
		free_all(g, 1);
	}
	g->map[0] = new_line;
	g->map[1] = NULL;
}

void	check_surrounded_by_walls(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == '0' || g->map[i][j] == 'N'
				|| g->map[i][j] == 'S' ||
				g->map[i][j] == 'E' || g->map[i][j] == 'W')
			{
				if (check_adjacent(g, i, j))
				{
					print_error("Map is not properly enclosed by walls\n");
					free_all(g, 1);
				}
				ft_replace(g->map[i], " \t\n\r\v\f", '1');
			}
			j++;
		}
		i++;
	}
	chech_edges(g);
}
