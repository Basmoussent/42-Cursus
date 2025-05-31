/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.h										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/11 14:15:28 by bdenfir		   #+#	#+#			 */
/*   Updated: 2024/12/11 17:51:19 by bdenfir		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdbool.h>

# ifndef WIN_SIZE
#  define WIN_SIZE 100
# endif

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	void	*img_char;
}	t_vars;

typedef struct s_info {
	int	rows;
	int	cols;
	int	player_count;
	int	exit_count;
	int	collectible_count;
	int	collected;
	int	move;
	int	exit_found;
}	t_info;

typedef struct s_tuple{
	int	x;
	int	y;
}	t_tuple;

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;
	int		img_size;
	char	**map;
	t_info	map_info;
	int		player_x;
	int		player_y;
}	t_game;

enum {
	W = 119,
	S = 115,
	A = 97,
	D = 100,
	ESC = 65307,
	LEFT = 65361,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363
};

char	**read_map(char *name, t_info *map);
void	error_exit(char *msg);
int		free_game(t_game *game, char *str);
void	get_player(t_game *game, t_info map_info);
void	next_move(t_game *game, int new_x, int new_y);
void	render_map(t_game *game);
void	clear_assets(t_game *game);
int		valid_path(char **str, t_info map);
void	free_map(char **map_array, int rows, char *line, int fd);
void	init_game(t_game *game, char **map, t_info map_info);
int		free_game2(t_game *game);

#endif