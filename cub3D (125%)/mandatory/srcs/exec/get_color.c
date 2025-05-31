/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:56:11 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/12 20:15:38 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	*find_side(t_game *game, t_rayon *rayon)
{
	t_img	*tex;

	if (game->map[rayon->map_y][rayon->map_x] == 'D'
		|| game->map[rayon->map_y][rayon->map_x] == 'O')
		return (game->tex->no_t);
	tex = game->tex->no_t;
	if (rayon->side == 1)
	{
		if (rayon->dir_y > 0)
			tex = game->tex->so_t;
		else
			tex = game->tex->no_t;
	}
	else
	{
		if (rayon->dir_x < 0)
			tex = game->tex->we_t;
		else
			tex = game->tex->ea_t;
	}
	return (tex);
}

int	get_textures(t_game *game, t_rayon *rayon, int **buffer, int x)
{
	t_tex_info	t_info;
	t_img		*tex_dir;
	double		step;
	int			y;

	tex_dir = find_side(game, rayon);
	t_info.x = (int)(rayon->wall_x * (double)tex_dir->width);
	if ((rayon->side == 0 && rayon->dir_x < 0)
		|| (rayon->side == 1 && rayon->dir_y > 0))
		t_info.x = tex_dir->width - t_info.x - 1;
	step = 1.0 * tex_dir->height / rayon->line_height;
	t_info.pos = (rayon->draw_start - WIN_HEIGHT / 2
			+ rayon->line_height / 2) * step;
	y = rayon->draw_start;
	while (y < rayon->draw_end)
	{
		t_info.y = (int)t_info.pos % tex_dir->height;
		t_info.pos += step;
		buffer[y][x] = *(int *)(tex_dir->addr + ((t_info.y
						* tex_dir->line_length) + t_info.x
					* (tex_dir->bits_per_pixel / 8)));
		y++;
	}
	return (y - 1);
}

void	get_color(t_game *game, t_rayon *rayon, int **buffer, int x)
{
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < rayon->draw_start)
		{
			if (game->sun->is_active && x < 100 && y < 100)
				buffer[y][x] = get_sun_color(game, x, y);
			else
				buffer[y][x] = game->tex->ceili_t;
		}
		else if (y >= rayon->draw_start && y <= rayon->draw_end)
			y += get_textures(game, rayon, buffer, x);
		else
			buffer[y][x] = game->tex->floor_t;
		y++;
	}
}
