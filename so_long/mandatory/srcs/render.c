/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   render.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/12 15:50:56 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/12/12 16:14:00 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "struct.h"

void	load_textures(t_game *game)
{
	int	img_width;
	int	img_height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &img_width, &img_height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
			"assets/floor.xpm", &img_width, &img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"assets/pacman1.xpm", &img_width, &img_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"assets/collectible.xpm", &img_width, &img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &img_width, &img_height);
	if (!game->wall_img || !game->floor_img || !game->player_img
		|| !game->collectible_img || !game->exit_img)
		free_game(game, "Couldn't load ressources !");
}

void	render_map(t_game *game)
{
	int		y;
	int		x;
	void	*img;

	y = -1;
	while (++y < game->map_info.rows)
	{
		x = 0;
		while (x < game->map_info.cols)
		{
			if (game->map[y][x] == '1')
				img = game->wall_img;
			else if (game->map[y][x] == 'C')
				img = game->collectible_img;
			else if (game->map[y][x] == 'E')
				img = game->exit_img;
			else
				img = game->floor_img;
			mlx_put_image_to_window(game->mlx, game->win, img,
				x * game->img_size, y * game->img_size);
			x++;
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		game->player_x * game->img_size, game->player_y * game->img_size);
}

int	handle_keypress(int kc, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (kc == W || kc == UP)
		new_y--;
	else if (kc == S || kc == DOWN)
		new_y++;
	else if (kc == A || kc == LEFT)
		new_x--;
	else if (kc == D || kc == RIGHT)
		new_x++;
	else if (kc == ESC)
		free_game(game, NULL);
	if (game->map[new_y][new_x] != '1' && (kc == W || kc == S
		|| kc == A || kc == D))
		next_move(game, new_x, new_y);
	if (game->map[new_y][new_x] != '1' && (kc == UP || kc == DOWN
		|| kc == LEFT || kc == RIGHT))
		next_move(game, new_x, new_y);
	return (0);
}

void	init_game(t_game *game, char **map, t_info map_info)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		free_game(game, "couldnt initialise window");
	game->img_size = WIN_SIZE;
	game->win = mlx_new_window(game->mlx, map_info.cols * game->img_size,
			map_info.rows * game->img_size, "so_long");
	if (!game->win)
		free_game(game, "Failed to create window");
	game->map = map;
	game->map_info = map_info;
	get_player(game, map_info);
	load_textures(game);
	render_map(game);
	mlx_key_hook(game->win, handle_keypress, game);
	mlx_hook(game->win, 17, 0, free_game2, game);
	mlx_loop(game->mlx);
}
