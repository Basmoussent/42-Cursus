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
	write(2, "Error\n", 6);
	perror(msg);
	exit(EXIT_FAILURE);
}

int	free_game(t_game *game, char *str)
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
	if (game->mlx && game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (str)
		error_exit(str);
	exit(0);
	return (0);
}

void	get_player(t_game *game, t_info map_info)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
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
}

void	next_move(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E')
	{	
		if (game->map_info.collected != game->map_info.collectible_count)
			return ;
		else
		{
			ft_putstr_fd("Yipeeeeeeeeeeeeeeee !\n", 1);
			free_game(game, NULL);
		}
	}
	ft_putnbr_fd(game->map_info.move, 1);
	ft_putstr_fd("\n", 1);
	game->map_info.move++;
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
}
