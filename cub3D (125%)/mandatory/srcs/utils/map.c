/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:05:39 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/12 13:16:47 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_walkable(t_game *game, int x, int y)
{
	int	real_x;
	int	real_y;

	real_x = (int)game->p->pos_x - MAP_WIDTH / (2 * 15) + x / 15;
	real_y = (int)game->p->pos_y - MAP_HEIGHT / (2 * 15) + y / 15;
	if (real_y < 0 || real_y >= ft_size(game->map))
		return (0);
	if (real_x < 0 || real_x >= (int)ft_strlen(game->map[real_y]))
		return (0);
	if (game->map[real_y][real_x] == '0' || game->map[real_y][real_x] == 'N'
		|| game->map[real_y][real_x] == 'W' || game->map[real_y][real_x] == 'E'
		|| game->map[real_y][real_x] == 'S')
		return (1);
	return (0);
}

// D ou O (o majuscule) pour les portes
static int	is_wall(t_game *game, int x, int y)
{
	int	real_x;
	int	real_y;

	real_x = (int)game->p->pos_x - MAP_WIDTH / (2 * 15) + x / 15;
	real_y = (int)game->p->pos_y - MAP_HEIGHT / (2 * 15) + y / 15;
	if (real_y < 0 || real_y >= ft_size(game->map))
		return (0);
	if (real_x < 0 || real_x >= (int)ft_strlen(game->map[real_y]))
		return (0);
	if (game->map[real_y][real_x] == 'D' || game->map[real_y][real_x] == 'O')
		return (1);
	return (0);
}

// MAP WHIDTH 198   / 15
// MAP HEIGHT 198   / 15
static void	fill_map(t_game *game, int **buffer)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if ((x / 15) == 6 && (y / 15) == 6)
				buffer[y][x] = 255;
			else if (is_walkable(game, x, y))
				buffer[y][x] = 15837961;
			else if (is_wall(game, x, y))
				buffer[y][x] = 53317;
			else
				buffer[y][x] = 0;
			x++;
		}
		y++;
	}
}

static int	**init_map_buffer(t_game *game)
{
	int	**buffer;
	int	x;

	x = 0;
	buffer = ft_calloc(sizeof(int *), MAP_HEIGHT + 1);
	if (!buffer)
		return (free_all(game, 1), NULL);
	while (x < MAP_HEIGHT)
	{
		buffer[x] = ft_calloc(sizeof(int), MAP_WIDTH);
		if (!buffer[x])
			return (free_tab((void **)buffer), free_all(game, 1), NULL);
		x++;
	}
	buffer[x] = NULL;
	return (buffer);
}

int	print_minimap(t_game *game)
{
	int	**buffer;
	int	x;
	int	y;

	x = 0;
	y = 0;
	buffer = init_map_buffer(game);
	fill_map(game, buffer);
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			my_mlx_pixel_put(game->minimap, x, y, buffer[y][x]);
			x++;
		}
		y++;
	}
	free_tab((void **)buffer);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap->img,
		WIN_WIDTH - MAP_WIDTH - 10, 10);
	return (1);
}
