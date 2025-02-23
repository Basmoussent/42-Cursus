/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   dfs.c											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/23 12:24:13 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/12/23 12:24:14 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "struct.h"

int	infection(char **str, int x, int y, t_info *map)
{
	if (x < 0 || y < 0 || x >= map->rows || y >= map->cols)
		return (0);
	if (str[x][y] == 'E')
		map->exit_found = 1;
	if (str[x][y] == '1' || str[x][y] == 'x'
		|| str[x][y] == 'X' || str[x][y] == '-')
		return (0);
	if (str[x][y] == 'C')
	{
		str[x][y] = 'X';
		map->collected++;
	}
	else if (str[x][y] == '0')
		str[x][y] = 'x';
	else if (str[x][y] == 'P')
		str[x][y] = '-';
	if (map->collected == map->collectible_count && map->exit_found)
		return (1);
	return (infection(str, x + 1, y, map) || infection(str, x - 1, y, map)
		|| infection(str, x, y + 1, map) || infection(str, x, y - 1, map));
}

void	cure(char **str, t_info map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map.rows)
	{
		y = 0;
		while (y < map.cols)
		{
			if (str[x] != NULL && str[x][y])
			{
				if (str[x][y] == 'x')
					str[x][y] = '0';
				else if (str[x][y] == 'X')
					str[x][y] = 'C';
				else if (str[x][y] == '-')
					str[x][y] = 'P';
			}
			y++;
		}
		x++;
	}
}

t_tuple	get_spawn_point(char **str, t_info map)
{
	t_tuple	spawn;

	spawn = (t_tuple){0};
	while (spawn.x < map.rows)
	{
		spawn.y = 0;
		while (spawn.y < map.cols)
		{
			if (str[spawn.x][spawn.y] == 'P')
				return (spawn);
			spawn.y++;
		}
		spawn.x++;
	}
	return (spawn);
}

int	check_cases(char **str, t_info map)
{
	t_tuple	spawn;

	spawn = (t_tuple){0};
	while (spawn.x < map.rows)
	{
		spawn.y = 0;
		while (spawn.y < map.cols)
		{
			if (str[spawn.x][spawn.y] == 'P')
				;
			else if (str[spawn.x][spawn.y] == '1')
				;
			else if (str[spawn.x][spawn.y] == 'E')
				;
			else if (str[spawn.x][spawn.y] == '0')
				;
			else if (str[spawn.x][spawn.y] == 'C')
				;
			else
				return (1);
			spawn.y++;
		}
		spawn.x++;
	}
	return (0);
}

int	valid_path(char **str, t_info map)
{
	t_tuple	spawn;

	spawn = get_spawn_point(str, map);
	if (check_cases(str, map))
		return (0);
	if (infection(str, spawn.x, spawn.y, &map)
		&& map.collected == map.collectible_count)
	{	
		cure(str, map);
		map.collected = 0;
		return (1);
	}
	return (0);
}
