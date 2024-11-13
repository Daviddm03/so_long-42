/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:53:26 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/11/12 11:09:14 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	player_update_image(t_game *game)
{
	int	img_w;
	int	img_h;

	img_w = IMG_WIDTH;
	img_h = IMG_HEIGHT;
	if (!game->img[3])
		game->img[3] = mlx_xpm_file_to_image(game->mlx_ptr,
				"images/player.xpm", &img_w, &img_h);
}

void	player_w(t_game *game)
{
	player_update_image(game);
	move_player(game, game->player_x, game->player_y - 1);
}

void	player_s(t_game *game)
{
	player_update_image(game);
	move_player(game, game->player_x, game->player_y + 1);
}

void	player_d(t_game *game)
{
	player_update_image(game);
	move_player(game, game->player_x + 1, game->player_y);
}

void	player_a(t_game *game)
{
	player_update_image(game);
	move_player(game, game->player_x - 1, game->player_y);
}
