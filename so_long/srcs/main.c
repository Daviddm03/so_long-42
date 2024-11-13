/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:25:55 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/11/12 13:23:37 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map_name(char *map_name)
{
	int	i;

	i = ft_strlen(map_name);
	if (ft_strnstr((map_name + (i - 4)), ".ber", 4))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		i;

	i = 0;
	if (ac != 2)
		return (ft_printf("Usage:\n%s path_to_map_file.ber\n",
				av[0]), 1);
	game.map = init_map();
	if (!game.map)
		return (1);
	game.moves = 0;
	game.last_player_x = -1;
	game.last_player_y = -1;
	while (i < 6)
		game.img[i++] = NULL;
	load_map(&game, av[1]);
	init_mlx(&game);
	gameplay(&game);
	load_img(&game);
	mlx_loop_hook(game.mlx_ptr, put_image, &game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
	return (0);
}
