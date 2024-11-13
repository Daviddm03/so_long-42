/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:32:54 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/11/12 13:25:16 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		ft_printf("Error\nMap memory allocation failed\n");
		return (NULL);
	}
	map->map_bytes = NULL;
	map->height = 0;
	map->width = 0;
	map->collectables = 0;
	map->exit = 0;
	map->player = 0;
	return (map);
}

void	init_mlx(t_game *game)
{
	if (!game)
	{
		ft_printf("Error\nGame structure is not initialized.\n");
		exit(EXIT_FAILURE);
	}
	if (!game->map)
	{
		ft_printf("Error\nMap structure is not initialized.\n");
		exit(EXIT_FAILURE);
	}
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_printf("Error\nCouldn't initialize Minilibx.\n");
		exit(EXIT_FAILURE);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->map->width * 64, game->map->height * 64, "so_long");
	if (!game->win_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		ft_printf("Error\nCouldn't create the window\n");
		exit(EXIT_FAILURE);
	}
}

int	map_checker(t_game *game)
{
	if (check_line_length(game->map) && check_map_elements(game->map)
		&& check_walls(game->map) && check_map_char(game->map)
		&& check_accessibility(game))
		return (1);
	return (0);
}

void	fill_in_map_bytes(t_map *map, char *map_name)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nUnable to open map file %s\n", map_name);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		process_line(map, line, i);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	if (i != map->height)
	{
		ft_printf("Erro\nInvalid map height\n");
		handle_line_error(map->map_bytes, i);
		exit(EXIT_FAILURE);
	}
}

void	load_map(t_game *game, char *map_name)
{
	game->map->height = get_lines_am(map_name);
	if (game->map->height <= 0)
	{
		ft_printf("Error\nEmpty or invalid map\n");
		free(game->map);
		exit(EXIT_FAILURE);
	}
	game->map->map_bytes = (char **)ft_calloc
		(game->map->height + 1, sizeof(char *));
	if (!game->map->map_bytes)
	{
		ft_printf("Error\nMemory alloc failed.\n");
		free(game->map);
		exit(EXIT_FAILURE);
	}
	fill_in_map_bytes(game->map, map_name);
	find_player_position(game);
	find_exit_position(game);
	check_map_validity(game);
}
