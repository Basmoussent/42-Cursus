/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/11 18:15:38 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/12/12 18:13:07 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "struct.h"

void	error_exit(char *msg)
{
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

int	free_game(t_game *game)
{
	int	i;

	clear_assets(game);
	if (game->map)
	{
		i = -1;
		while (++i < game->map_info.rows)
			free(game->map[i]);
		free(game->map);
	}
	if (game->mlx)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}

void	get_player(t_game *game, t_info map_info)
{
	int	y;
	int	x;

	y = 0;
	if (!game->map)
		error_exit("Map not initialized");
	while (y < map_info.rows)
	{
		x = 0;
		while (x < map_info.cols)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	error_exit("Player position not found on map");
}

void	next_move(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E')
	{	
		if (game->map_info.collected != game->map_info.collectible_count)
			return ;
		else
			free_game(game);
	}
	game->map_info.move++;
	if (game->map[new_y][new_x] == 'K')
		free_game(game);
	game->map[game->player_y][game->player_x] = '0';
	if (game->map[new_y][new_x] == 'C')
		game->map_info.collected++;
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	render_map(game);
}

void	clear_assets(t_game *game)
{
	if (game->play_sp[0])
		mlx_destroy_image(game->mlx, game->play_sp[0]);
	if (game->play_sp[1])
		mlx_destroy_image(game->mlx, game->play_sp[1]);
	if (game->play_sp[2])
		mlx_destroy_image(game->mlx, game->play_sp[2]);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->patrol_img)
		mlx_destroy_image(game->mlx, game->patrol_img);
}
