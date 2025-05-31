/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:08:07 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/13 11:55:41 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	init_image(void *mlx, t_img *img)
{
	img->img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img->img)
		return (0);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (0);
	return (1);
}

int	init_graphical(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	if (!game->win)
		return (free(game->img), game->img = NULL, free_all(game, 1), 1);
	if (!init_image(game->mlx, game->img))
		return (free_all(game, 1), 1);
	return (1);
}
