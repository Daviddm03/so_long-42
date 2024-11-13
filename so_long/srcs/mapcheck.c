/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:26:21 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/11/12 11:44:04 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_lines_am(char *map_name)
{
	char	*line;
	int		fd;
	int		lines_am;

	lines_am = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_printf("Error\nreading the map\n");
	line = get_next_line(fd);
	while (line)
	{
		lines_am++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines_am);
}

int	check_line_length(t_map *map)
{
	int	i;

	i = 1;
	if (!map || !map->map_bytes)
	{
		ft_printf("Error\nMap is not properly initialized.\n");
		return (0);
	}
	while (map->map_bytes[i])
	{
		if (ft_strlen(map->map_bytes[i]) != ft_strlen (map->map_bytes[0]))
		{
			ft_printf("Error\nThe lines doesn't have the same length.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map_elements(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	if (!map || !map->map_bytes)
		return (ft_printf("Error\nMap is not properly initialized.\n"), 0);
	while (map->map_bytes[x])
	{
		y = 0;
		while (map->map_bytes[x][y])
		{
			if (map->map_bytes[x][y] == 'P')
				map->player++;
			else if (map->map_bytes[x][y] == 'C')
				map->collectables++;
			else if (map->map_bytes[x][y] == 'E')
				map->exit++;
			y++;
		}
		x++;
	}
	if (map->player != 1 || map->exit != 1 || map->collectables == 0)
		return (ft_printf("Error\nThe number of C, P, or E is wrong\n"), 0);
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	if (!map || !map->map_bytes)
		return (ft_printf("Error\nMap is not properly initialized.\n"), 0);
	while (i < map->height)
	{
		if ((int)strlen(map->map_bytes[i]) < map->width
			|| map->map_bytes[i][0] != '1'
			|| map->map_bytes[i][map->width - 1] != '1')
			return (ft_printf("Error\nThe map must have a border\n",
					i, map->map_bytes[i][0],
				map->map_bytes[i][map->width - 1]), 0);
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (map->map_bytes[0][i] != '1' ||
			map->map_bytes[map->height - 1][i] != '1')
			return (ft_printf
				("Error\nThe map must have a border.\n"), 0);
		i++;
	}
	return (1);
}

int	check_map_char(t_map *map)
{
	char	i;
	int		x;
	int		y;

	x = 0;
	if (!map || !map->map_bytes)
		return (ft_printf("Error\nMap is not properly initialized.\n"), 0);
	while (map->map_bytes[x])
	{
		y = 0;
		while (map->map_bytes[x][y])
		{
			i = map->map_bytes[x][y];
			if (i != '1' && i != '0' && i != 'E'
				&& i != 'P' && i != 'C')
			{
				ft_printf("Error\nThe map has inappropriate characters\n");
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}
