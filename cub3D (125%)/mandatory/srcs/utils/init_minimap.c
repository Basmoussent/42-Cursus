/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:15:53 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/13 12:15:59 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_minimap(t_game *game)
{
	game->minimap->img = mlx_new_image(game->mlx, MAP_WIDTH, MAP_HEIGHT);
	if (!game->minimap->img)
		return (0);
	game->minimap->addr = mlx_get_data_addr(game->minimap->img,
			&game->minimap->bits_per_pixel, &game->minimap->line_length,
			&game->minimap->endian);
	if (!game->minimap->addr)
		return (0);
	return (1);
}

void	chech_edges(t_game *g)
{
	int	i;
	int	x;

	i = ft_size(g->map);
	x = -1;
	while (++x < i)
	{
		if (x == 0 && occur(g->map[x], 'D') != 0)
		{
			print_error("Door on edge unauthorized\n");
			free_all(g, 1);
		}
		if (g->map[x][0] == 'D' || g->map[x][ft_strlen(g->map[x]) - 1] == 'D')
		{
			print_error("Door on edge unauthorized\n");
			free_all(g, 1);
		}
		if (x == i && occur(g->map[x], 'D') != 0)
		{
			print_error("Door on edge unauthorized\n");
			free_all(g, 1);
		}
	}
}
