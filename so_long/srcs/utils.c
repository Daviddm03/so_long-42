/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:49:45 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/11/12 14:16:51 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	find_player_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map_bytes[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	game->player_x = -1;
	game->player_y = -1;
}

void	find_exit_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map_bytes[y][x] == 'E')
			{
				game->map->exit_x = x;
				game->map->exit_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	game->map->exit_x = -1;
	game->map->exit_y = -1;
}

void	handle_line_error(char **map_bytes, int i)
{
	while (i >= 0)
	{
		free(map_bytes[i]);
		i--;
	}
	free(map_bytes);
}

void	process_line(t_map *map, char *line, int i)
{
	int	line_length;

	line_length = ft_strlen(line);
	if (line[line_length - 1] == '\n')
		line[--line_length] = '\0';
	if (i == 0)
		map->width = line_length;
	else if (line_length != map->width)
	{
		ft_printf("Error: Line %d length does not match map width %d.\n",
			i, map->width);
		handle_line_error(map->map_bytes, i);
		free(line);
		exit(EXIT_FAILURE);
	}
	map->map_bytes[i] = ft_strdup(line);
	if (!map->map_bytes[i])
	{
		ft_printf("Error: Memory allocation failed for line %d.\n", i);
		handle_line_error(map->map_bytes, i);
		exit(EXIT_FAILURE);
	}
	free(line);
}
