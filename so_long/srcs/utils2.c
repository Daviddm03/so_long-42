/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:07:53 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/11/12 14:43:18 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_validity(t_game *game)
{
	if (game->player_x == -1 || game->player_y == -1)
	{
		ft_printf("Error\nInvalid player position.\n");
		free(game->map->map_bytes);
		exit(EXIT_FAILURE);
	}
	if (!map_checker(game))
	{
		free(game->map->map_bytes);
		exit(EXIT_FAILURE);
	}
}

void	handle_movement(int keycode, int *new_x, int *new_y, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		(*new_y)--;
		player_w(game);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		(*new_y)++;
		player_s(game);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		(*new_x)++;
		player_d(game);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		(*new_x)--;
		player_a(game);
	}
}

void	handle_player_position(t_game *game, int old_x, int old_y)
{
	if (game->map->map_bytes[game->player_y][game->player_x] == 'C')
		game->map->collectables -= 1;
	game->map->map_bytes[game->player_y][game->player_x] = 'P';
	if (game->map->exit_y == old_y && game->map->exit_x == old_x)
		game->map->map_bytes[old_y][old_x] = 'E';
	else
		game->map->map_bytes[old_y][old_x] = '0';
}

void	move_player(t_game *game, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = game->player_x;
	old_y = game->player_y;
	game->player_x = new_x;
	game->player_y = new_y;
	if (game->map->map_bytes[game->player_y][game->player_x]
		== 'E' && game->map->collectables == 0)
		exit_game(game);
	else if (game->map->map_bytes[game->player_y][game->player_x] == '1' ||
			game->map->map_bytes[game->player_y][game->player_x] == 'E')
	{
		game->player_x = old_x;
		game->player_y = old_y;
	}
	else
	{
		handle_player_position(game, old_x, old_y);
		put_image(game);
	}
}
