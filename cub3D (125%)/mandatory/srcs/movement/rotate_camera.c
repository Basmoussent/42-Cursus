/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:31:22 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/10 15:05:28 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
To rotate a vactor, simply multiply it with the rotation matrix
[ cos(a) -sin(a) ]
[ sin(a)  cos(a) ]
(where a is the magnitude of rotation)
*/

void	rotation(t_game *game, double a)
{
	double	tmp;

	tmp = game->p->dir_x;
	game->p->dir_x = game->p->dir_x * cos(a) - game->p->dir_y * sin(a);
	game->p->dir_y = tmp * sin(a) + game->p->dir_y * cos(a);
	tmp = game->p->plane_x;
	game->p->plane_x = game->p->plane_x * cos(a) - game->p->plane_y * sin(a);
	game->p->plane_y = tmp * sin(a) + game->p->plane_y * cos(a);
	rendering(game);
}

// Left = 4 / Right = 5
void	rotate_camera(t_game *game)
{
	if (game->key_bool[4] || game->key_bool[6])
		rotation(game, ROTSPEED * -1);
	if (game->key_bool[5] || game->key_bool[7])
		rotation(game, ROTSPEED);
}
