/* ************************************************************************** */
/*									  */
/*							:::	 ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*						  +:+ +:+	   +:+	*/
/*   By: bdenfir <bdenfir@42.fr>					+#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	 */
/*   Created: 2025/03/04 07:29:48 by bdenfir		   #+#  #+#		  */
/*   Updated: 2025/03/12 14:52:55 by agozlan          ###   ########.fr       */
/*									  */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *g, char *file)
{
	g->tex = ft_calloc(1, sizeof(t_texture));
	g->p = ft_calloc(1, sizeof(t_player));
	g->mlx = NULL;
	g->map = NULL;
	g->minimap = NULL;
	g->img = NULL;
	g->doors = NULL;
	g->sun = NULL;
	if (!g->tex || !g->p)
		free_all(g, 1);
	g->tex->fd = open(file, O_RDONLY);
	if (g->tex->fd == -1)
	{
		print_error("Failed to open file\n");
		free_all(g, 127);
	}
	g->mlx = mlx_init();
	if (!g->mlx)
		free_all(g, 1);
	init_keybool(g);
	g->tex->floor_t = -1;
	g->tex->ceili_t = -1;
	g->p->dir_x = -2;
	g->p->plane_y = 0.66;
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_img	minimap;

	if (argc != 2)
	{
		print_error("Usage: ./cub3d <map.cub>");
		return (1);
	}
	if (argv[1] && ft_strlen(argv[1]) >= 4
		&& !ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
	{
		minimap = (t_img){0};
		init_game(&game, argv[1]);
		parsing(&game);
		game.img = ft_calloc(1, sizeof(t_img));
		game.minimap = &minimap;
		execution(&game);
		free_all(&game, 0);
	}
	else
	{
		print_error("Wrong file extension. only .cub are supported\n");
		return (1);
	}
	return (0);
}
