/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:01:11 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/11/12 12:35:35 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_img(t_game *game)
{
	int	size;
	int	i;

	i = 0;
	size = 64;
	game->img[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/floor.xpm", &size, &size);
	game->img[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/wall2.xpm", &size, &size);
	game->img[2] = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/key.xpm", &size, &size);
	game->img[3] = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/fantasminhacamarada.xpm", &size, &size);
	game->img[4] = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/exit.xpm", &size, &size);
	game->img[5] = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/exit.xpm", &size, &size);
	while (i < 6)
	{
		if (!game->img[i])
			ft_printf("Erro: Falha ao carregar imagem %d\n", i);
		i++;
	}
}

void	render_img(t_game *game, int i, int j)
{
	char	img;

	img = game->map->map_bytes[i][j];
	if (img == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img[1], j * 64, i * 64);
	else if (img == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img[0], j * 64, i * 64);
	else if (img == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img[2], j * 64, i * 64);
	else if (img == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img[4], j * 64, i * 64);
}

int	put_image(void *param)
{
	t_game	*game;
	int		i;
	int		j;

	game = (t_game *)param;
	if (game->last_player_x >= 0 && game->last_player_y >= 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img[0],
			game->last_player_x * 64, game->last_player_y * 64);
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (game->map->map_bytes[i][j])
		{
			render_img(game, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img[3], game->player_x * 64, game->player_y * 64);
	return (0);
}
