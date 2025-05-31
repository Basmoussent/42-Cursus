/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:32:26 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/12 20:17:07 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	upd_key_bool(int keycode, t_game *game, int x)
{
	if (keycode == W)
		game->key_bool[0] = x;
	if (keycode == S)
		game->key_bool[1] = x;
	if (keycode == A)
		game->key_bool[2] = x;
	if (keycode == D)
		game->key_bool[3] = x;
	if (keycode == LEFT)
		game->key_bool[4] = x;
	if (keycode == RIGHT)
		game->key_bool[5] = x;
}

int	ft_release(int keycode, t_game *game)
{
	upd_key_bool(keycode, game, 0);
	return (0);
}

int	ft_button(int keycode, t_game *game)
{
	if (keycode == ESC)
		free_all(game, 0);
	if (keycode == 'c' && !game->sun->is_active)
	{
		game->sun->is_active = 1;
		game->sun->radius = 0;
		game->sun->growing = 1;
	}
	upd_key_bool(keycode, game, 1);
	return (0);
}

int	ft_mouse_release(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->key_bool[6] = 0;
	else if (button == 3)
		game->key_bool[7] = 0;
	return (0);
}

void	key_controls(t_game *game)
{
	mlx_hook(game->win, 17, 0, cross_close, game);
	mlx_hook(game->win, 2, 1L << 0, ft_button, game);
	mlx_hook(game->win, 3, 1L << 1, ft_release, game);
	mlx_hook(game->win, 4, 1L << 2, ft_mouse, game);
	mlx_hook(game->win, 5, 1L << 3, ft_mouse_release, game);
}
