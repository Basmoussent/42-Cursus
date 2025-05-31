/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:38:59 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/13 11:40:45 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_texture {
	char	*file;
	int		fd;
	t_img	*no_t;
	t_img	*so_t;
	t_img	*we_t;
	t_img	*ea_t;
	int		floor_t;
	int		ceili_t;
	int		loaded;
}	t_texture;

typedef struct s_player {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_door {
	int				x;
	int				y;
	int				is_open;
	struct timeval	time;
}	t_door;

typedef struct s_sun {
	int		is_active;
	int		radius;
	int		max_radius;
	int		growing;
	int		x_center;
	int		y_center;
}	t_sun;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_player	*p;
	t_texture	*tex;
	t_img		*img;
	t_img		*minimap;
	int			key_bool[8];
	t_door		*doors;
	int			nb_doors;
	t_sun		*sun;
}	t_game;

typedef struct s_rayon
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		map_x;
	int		map_y;
	int		side;
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
}	t_rayon;

typedef struct s_tex_info
{
	int		x;
	int		y;
	double	pos;
}	t_tex_info;

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

#endif
