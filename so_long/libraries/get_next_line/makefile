CYAN 	= \033[1;36m

FILES = get_next_line.c get_next_line_utils.c

BONUS_FILES = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(FILES:.c=.o)
BONUS_OBJS = $(BONUS_FILES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
HEADER = get_next_line.h get_next_line_bonus.h
LIBC = ar -rcs
NAME = gnl.a

all: $(NAME)

bonus: $(NAME) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) -c $(BONUS_FILES)
	@$(LIBC) $(NAME) $(BONUS_OBJS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -c $(FILES)
	@$(LIBC) $(NAME) $(OBJS) 
	@echo "$(CYAN)----> GNL COMPILED! <----"

clean: 
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus