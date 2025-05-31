/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agozlan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:20:11 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/12 13:23:14 by agozlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_door_struct(t_game *game, int x, int y, int *door_count)
{
	game->doors[*door_count].x = x;
	game->doors[*door_count].y = y;
	game->doors[*door_count].is_open = 0;
	gettimeofday(&game->doors[*door_count].time, NULL);
	(*door_count)++;
}

static void	find_doors(t_game *game, int door_count)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'D')
				init_door_struct(game, x, y, &door_count);
			x++;
		}
		y++;
	}
}

void	init_doors(t_game *game)
{
	int	y;
	int	door_count;

	door_count = 0;
	y = -1;
	while (game->map[++y])
		door_count += occur(game->map[y], 'D');
	game->nb_doors = door_count;
	game->doors = ft_calloc(door_count, sizeof(t_door));
	if (!game->doors)
		free_all(game, 1);
	find_doors(game, 0);
}
