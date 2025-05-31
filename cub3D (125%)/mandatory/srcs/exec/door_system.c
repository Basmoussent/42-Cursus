/* ************************************************************************** */
/*									  */
/*							:::	 ::::::::   */
/*   door_system.c                                      :+:      :+:    :+:   */
/*						  +:+ +:+	   +:+	*/
/*   By: bdenfir <bdenfir@student.42.fr>			+#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	 */
/*   Created: 2025/03/11 10:00:00 by bdenfir		   #+#  #+#		  */
/*   Updated: 2025/03/12 13:22:23 by agozlan          ###   ########.fr       */
/*									  */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player_on_door(t_game *game, int door_x, int door_y)
{
	double	buffer;

	buffer = 0.5;
	if ((int)game->p->pos_x == door_x && (int)game->p->pos_y == door_y)
		return (1);
	if (fabs(game->p->pos_x - door_x) < buffer
		&& fabs(game->p->pos_y - door_y) < buffer)
		return (1);
	return (0);
}

void	door_state(t_game *game, t_door *door, struct timeval current_time)
{
	door->is_open = !door->is_open;
	door->time = current_time;
	if (door->is_open)
		game->map[door->y][door->x] = 'O';
	else
		game->map[door->y][door->x] = 'D';
	rendering(game);
}

void	update_doors(t_game *game)
{
	struct timeval	current_time;
	int				i;
	long			elapsed;

	gettimeofday(&current_time, NULL);
	i = -1;
	while (++i < game->nb_doors)
	{
		elapsed = (current_time.tv_sec - game->doors[i].time.tv_sec)
			* 1000000 + (current_time.tv_usec - game->doors[i].time.tv_usec);
		if (elapsed >= 10000000)
		{
			if (game->doors[i].is_open
				&& is_player_on_door(game, game->doors[i].x, game->doors[i].y))
				game->doors[i].time = current_time;
			else
				door_state(game, &game->doors[i], current_time);
		}
	}
}
