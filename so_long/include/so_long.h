/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:28:42 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/11/12 12:57:02 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libraries/ft_printf/ft_printf.h"
# include "../libraries/libft/libft.h"
# include "../libraries/get_next_line/get_next_line.h"
# include "../libraries/get_next_line/get_next_line_bonus.h"
# include "../minilibx-linux/mlx.h"

# define IMG_HEIGHT 64
# define IMG_WIDTH 64
# define WIN_HEIGHT 960
# define WIN_WIDTH 540

# define KEY_ESC 65307
# define KEY_Q 113

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

/*STRUCTS*/
typedef struct s_map
{
	char	**map_bytes;
	int		height;
	int		width;
	int		collectables;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		player;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img[6];
	t_map	*map;
	int		player_x;
	int		player_y;
	int		last_player_x;
	int		last_player_y;
	int		moves;
	int		endgame;
}	t_game;

t_map	*init_map(void);
void	load_map(t_game *game, char *map_name);
int		get_lines_am(char *map_name);
void	init_mlx(t_game *game);
void	fill_in_map_bytes(t_map *map, char *map_name);
int		check_line_length(t_map *map);
int		check_map_elements(t_map *map);
int		check_walls(t_map *map);
int		check_map_char(t_map *map);
int		check_accessibility(t_game *game);
int		map_checker(t_game *game);
void	find_player_position(t_game *game);
void	load_img(t_game *game);
int		put_image(void *param);
int		exit_game(t_game *game);
void	player_a(t_game *game);
void	player_d(t_game *game);
void	player_s(t_game *game);
void	player_w(t_game *game);
void	gameplay(t_game *game);
void	find_exit_position(t_game *game);
void	handle_line_error(char **map_bytes, int i);
void	process_line(t_map *map, char *line, int i);
void	check_map_validity(t_game *game);
void	handle_movement(int keycode, int *new_x, int *new_y, t_game *game);
void	move_player(t_game *game, int new_x, int new_y);
void	free_game(t_game *game);

#endif