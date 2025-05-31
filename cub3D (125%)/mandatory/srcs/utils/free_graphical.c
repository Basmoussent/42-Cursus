/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graphical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:25:31 by agozlan           #+#    #+#             */
/*   Updated: 2025/03/10 15:06:19 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_graphical(int type, void *mlx, void *img, void *win)
{
	if (type == 3)
		mlx_destroy_image(mlx, img);
	if (type >= 2)
		mlx_destroy_window(mlx, win);
}

void	handle_malloc_fail(t_game *g, char **file, char *line, t_img *img)
{
	free_tab((void **)file);
	free(line);
	free(img);
	print_error("Malloc fail\n");
	free_all(g, 1);
}

void	check_file_format(char **file, char *line, t_img *img, t_game *g)
{
	if (file[1][strlen(file[1]) - 1] == '\n')
		file[1][strlen(file[1]) - 1] = '\0';
	ft_replace(file[1], " ", '\0');
	if (!(file[1] && ft_strlen(file[1]) >= 4 && !ft_strncmp(file[1]
				+ ft_strlen(file[1]) - 4, ".xpm", 4)))
	{
		free_tab((void **)file);
		free(line);
		free(img);
		print_error("Texture aren't in .xpm format\n");
		free_all(g, 1);
	}
}

void	destroy_img(t_game *g, t_img *img)
{
	mlx_destroy_image(g->mlx, img->img);
	free(img);
}
