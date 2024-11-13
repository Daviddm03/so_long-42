/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:15:51 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/11/12 14:25:13 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**copy_map(t_map *map)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!new_map)
		return (NULL);
	while (i < map->height)
	{
		new_map[i] = ft_strdup(map->map_bytes[i]);
		if (new_map[i] == NULL)
		{
			while (i > 0)
				free(new_map[--i]);
			free(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	flood_fill(char **map_bytes, int x, int y)
{
	if (x < 0 || y < 0 || map_bytes[y][x] == '1' || map_bytes[y][x] == 'G')
		return ;
	if (map_bytes[y][x] == '0' || map_bytes[y][x] == 'C' ||
		map_bytes[y][x] == 'P' || map_bytes[y][x] == 'E')
		map_bytes[y][x] = 'G';
	flood_fill(map_bytes, x + 1, y);
	flood_fill(map_bytes, x - 1, y);
	flood_fill(map_bytes, x, y + 1);
	flood_fill(map_bytes, x, y - 1);
}

int	valid_coordinates(t_game *game)
{
	if (game->player_x < 0 || game->player_x >= game->map->width
		|| game->player_y < 0 || game->player_y >= game->map->height)
	{
		ft_printf("Erro: Coordenadas inválidas: (%d, %d)\n",
			game->player_x, game->player_y);
		return (0);
	}
	return (1);
}

int	check_locked_items(char **new, int i)
{
	int	j;

	j = -1;
	while (new[i][++j])
	{
		if (new[i][j] == 'C' || new[i][j] == 'P' || new[i][j] == 'E')
		{
			ft_printf("Error\nLocked %c in (%d, %d)\n", new[i][j], i, j);
			while (new[i])
				free(new[i++]);
			free(new);
			return (0);
		}
	}
	return (1);
}

int	check_accessibility(t_game *game)
{
	char	**new;
	int		i;

	if (!valid_coordinates(game))
		return (0);
	new = copy_map(game->map);
	if (!new)
		return (0);
	flood_fill(new, game->player_x, game->player_y);
	i = -1;
	while (new[++i] != NULL)
	{
		if (!check_locked_items(new, i))
			return (0);
		free(new[i]);
	}
	return (free(new), 1);
}
