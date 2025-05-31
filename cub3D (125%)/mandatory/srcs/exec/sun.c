/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:38:31 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/12 20:15:16 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sun(t_game *game)
{
	game->sun = ft_calloc(1, sizeof(t_sun));
	if (!game->sun)
		free_all(game, 1);
	game->sun->is_active = 0;
	game->sun->radius = 0;
	game->sun->max_radius = 50;
	game->sun->growing = 1;
	game->sun->x_center = 50;
	game->sun->y_center = 50;
}

void	update_sun(t_game *game)
{
	if (!game->sun->is_active)
		return ;
	if (game->sun->growing)
	{
		game->sun->radius += 1;
		if (game->sun->radius >= game->sun->max_radius)
			game->sun->growing = 0;
	}
	else
	{
		game->sun->radius -= 1;
		if (game->sun->radius <= 0)
		{
			game->sun->is_active = 0;
			game->sun->growing = 1;
		}
	}
}

int	blend_colors(int color1, int color2, int alpha)
{
	int	r[6];

	r[0] = (color1 >> 16) & 0xFF;
	r[1] = (color1 >> 8) & 0xFF;
	r[2] = color1 & 0xFF;
	r[3] = (color2 >> 16) & 0xFF;
	r[4] = (color2 >> 8) & 0xFF;
	r[5] = color2 & 0xFF;
	r[0] = ((r[3] * alpha) + (r[0] * (255 - alpha))) / 255;
	r[1] = ((r[4] * alpha) + (r[1] * (255 - alpha))) / 255;
	r[2] = ((r[5] * alpha) + (r[2] * (255 - alpha))) / 255;
	return ((r[0] << 16) | (r[1] << 8) | r[2]);
}

int	get_sun_color(t_game *game, int x, int y)
{
	double	distance;
	double	normalized_distance;
	int		yellow;
	int		alpha;

	distance = sqrt(pow(x - game->sun->x_center, 2)
			+ pow(y - game->sun->y_center, 2));
	if (distance <= game->sun->radius)
	{
		normalized_distance = distance / game->sun->radius;
		alpha = (1.0 - normalized_distance) * 255;
		yellow = 0xFFFF00;
		return (blend_colors(game->tex->ceili_t, yellow, alpha));
	}
	return (game->tex->ceili_t);
}
