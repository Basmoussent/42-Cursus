/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:55:17 by bdenfir           #+#    #+#             */
/*   Updated: 2025/01/02 19:25:32 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	free_map(char **map_array, int rows, char *line, int fd)
{
	int	i;

	if (!map_array)
		return ;
	i = 0;
	while (i < rows)
	{
		if (map_array[i])
			free(map_array[i]);
		i++;
	}
	while (1 && fd != -1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
	if (fd != -1)
		close(fd);
	free(map_array);
}

int	free_game2(t_game *game)
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
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	map_info;
	t_game	game;
	char	**map;

	if (argc != 2)
		error_exit("Usage: ./so_long <map_file>");
	if (argv[1] && ft_strlen(argv[1]) >= 4
		&& !ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		map_info = (t_info){0};
		game = (t_game){0};
		map = read_map(argv[1], &map_info);
		if (!map || !*map)
			error_exit("Error occured while reading map.");
		game.map = map;
		game.map_info = map_info;
		if (valid_path(map, map_info))
			init_game(&game, map, map_info);
		else
			free_game(&game, "Invalid map caracteritic");
	}
	else
		error_exit("Wrong file extension");
	return (0);
}
