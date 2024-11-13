# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/19 17:21:17 by ddias-mo          #+#    #+#              #
#    Updated: 2024/11/12 13:01:11 by ddias-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
CYAN 	= \033[1;36m
GREEN   = \033[32m

#FILES
NAME = so_long
MAP_SRCS = start.c utils.c mapcheck.c game_draw.c game_update.c game_keys.c exit_game.c floodfill.c utils2.c
OBJS = $(SRCS:.c=.o)
SRCS = $(addprefix $(PATH_MAP)/, $(MAP_SRCS))  $(PATH_MAP)/main.c

#FLAGS
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

#COMMANDS
RM = rm -rf

#PATHS
PATH_MAP = srcs
PATH_LIBFT = libraries/libft
LIBFT = $(PATH_LIBFT)/libft.a
PATH_PRINTF = libraries/ft_printf
PRINTF = $(PATH_PRINTF)/libftprintf.a
PATH_GNL = libraries/get_next_line
GNL = $(PATH_GNL)/gnl.a
PATH_MLX = minilibx-linux

#RULES
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(PATH_LIBFT) --silent
	@make -C $(PATH_PRINTF) --silent
	@make -C $(PATH_GNL) --silent
	@$(CC) $(CFLAGS) $(OBJS) $(GNL) $(PRINTF) $(LIBFT) $(LFLAGS) -o $(NAME)
	@echo "$(CYAN)----> COMPILATION IS DONE! 🫡 <----"

$(PATH_MAP)/%.o: $(PATH_MAP)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@


clean: 
	@make clean -C $(PATH_LIBFT) --silent
	@make clean -C $(PATH_PRINTF) --silent
	@make clean -C $(PATH_GNL) --silent
	@$(RM) $(OBJS)
	@echo "$(CYAN)----> OBJS CLEANED 👌 <----"

fclean:	clean
	@make fclean -C $(PATH_LIBFT) --silent
	@make fclean -C $(PATH_PRINTF) --silent
	@make fclean -C $(PATH_GNL) --silent
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
