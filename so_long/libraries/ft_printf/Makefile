CYAN 	= \033[1;36m

FILES = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c \
		ft_putuns.c ft_puthex.c ft_putptr.c

OBJS = $(FILES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
HEADER = ft_printf.h
LIBC = ar -rcs
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -c $(FILES)
	@$(LIBC)	$(NAME)	$(OBJS) 
	@echo "$(CYAN)----> PRINTF COMPILED! <----"

clean: 
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re