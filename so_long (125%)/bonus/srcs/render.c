/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   render.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/12 15:50:56 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/12/23 19:37:37 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "struct.h"

int	load_textures(t_game *game)
{
	int	img_width;
	int	img_height;

	game->play_sp[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/pacman1.xpm", &img_width, &img_height);
	game->play_sp[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/pacman2.xpm", &img_width, &img_height);
	game->play_sp[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/pacman3.xpm", &img_width, &img_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &img_width, &img_height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
			"assets/floor.xpm", &img_width, &img_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"assets/collectible.xpm", &img_width, &img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &img_width, &img_height);
	game->patrol_img = mlx_xpm_file_to_image(game->mlx,
			"assets/patrol.xpm", &img_width, &img_height);
	if (!game->wall_img || !game->floor_img || !game->play_sp[0]
		|| !game->play_sp[1] || !game->play_sp[2] || !game->collectible_img
		|| !game->exit_img || !game->patrol_img)
		return (1);
	return (0);
}

void	render_map(t_game *game)
{
	t_tuple	tuple;
	void	*img;

	tuple = (t_tuple){-1, -1};
	while (++tuple.y < game->map_info.rows)
	{
		tuple.x = -1;
		while (++tuple.x < game->map_info.cols)
		{
			if (game->map[tuple.y][tuple.x] == '1')
				img = game->wall_img;
			else if (game->map[tuple.y][tuple.x] == 'C')
				img = game->collectible_img;
			else if (game->map[tuple.y][tuple.x] == 'E')
				img = game->exit_img;
			else if (game->map[tuple.y][tuple.x] == 'K')
				img = game->patrol_img;
			else
				img = game->floor_img;
			mlx_put_image_to_window(game->mlx, game->win, img,
				tuple.x * game->img_size, tuple.y * game->img_size);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->play_sp[game->curr_sp],
		game->player_x * game->img_size, game->player_y * game->img_size);
}

int	update_animation(t_game *game)
{
	static int	frame_counter = 0;
	char		*label;

	label = ft_itoa(game->map_info.move);
	if (game->sprite_animation)
	{
		frame_counter++;
		if (frame_counter > 1000)
		{
			game->curr_sp = (game->curr_sp + 1) % 3;
			render_map(game);
			frame_counter = 0;
		}
	}
	mlx_string_put(game->mlx, game->win, game->img_size / 2,
		game->img_size / 2, 0xFFFFFF, label);
	free(label);
	return (0);
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
		free_game(game);
	else if (kc == V)
		game->sprite_animation = 1;
	if (game->map[new_y][new_x] != '1' && (kc == W
		|| kc == S || kc == A || kc == D))
		next_move(game, new_x, new_y);
	return (0);
}

void	init_game(t_game *game, char **map, t_info map_info)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		free_game(game);
	game->img_size = WIN_SIZE;
	game->win = mlx_new_window(game->mlx, map_info.cols * game->img_size,
			map_info.rows * game->img_size, "so_long");
	if (!game->win)
	{
		error_exit("Failed to create window");
		free_game(game);
	}
	if (!game->map)
		game->map = map;
	game->map_info = map_info;
	game->curr_sp = 0;
	game->sprite_animation = 0;
	get_player(game, map_info);
	if (load_textures(game))
		error_exit("Error loading ressources");
	render_map(game);
	mlx_key_hook(game->win, handle_keypress, game);
	mlx_hook(game->win, 17, 0, free_game, game);
	mlx_loop_hook(game->mlx, update_animation, game);
	mlx_loop(game->mlx);
}
