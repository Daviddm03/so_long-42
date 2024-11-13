/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:46:38 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/11/12 14:43:31 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	game_events(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	game->last_player_x = game->player_x;
	game->last_player_y = game->player_y;
	new_x = game->player_x;
	new_y = game->player_y;
	handle_movement(keycode, &new_x, &new_y, game);
	if (new_x >= 0 && new_x < game->map->width
		&& new_y >= 0 && new_y < game->map->height
		&& game->map->map_bytes[new_y][new_x] != '1')
	{
		if (game->map->map_bytes[new_y][new_x]
			== 'E' && game->map->collectables == 0)
			exit_game(game);
		game->player_x = new_x;
		game->player_y = new_y;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		put_image(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(game);
	else if (!game->endgame)
		game_events(keycode, game);
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 1L << 0, keypress, game);
	mlx_hook(game->win_ptr, 17, 1L << 17, exit_game, game);
}
