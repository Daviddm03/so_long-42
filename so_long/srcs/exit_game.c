/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:48:45 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/11/12 14:02:22 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_bytes[i] != NULL)
	{
		free(map->map_bytes[i]);
		i++;
	}
	free(map->map_bytes);
	free(map);
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
		free_map(game->map);
	while (i < 6)
	{
		if (game->img[i])
			mlx_destroy_image(game->mlx_ptr, game->img[i]);
		i++;
	}
	if (game->mlx_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}

int	exit_game(t_game *game)
{
	if (game->map->collectables == 0
		&& game->map->map_bytes[game->player_y]
		[game->player_x] == 'E')
		ft_printf("\033[0;36mCongrats, you won the game!\n");
	free_game(game);
	exit(0);
	return (0);
}
