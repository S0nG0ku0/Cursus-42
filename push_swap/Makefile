SRC = ./libft/ft_atoi.c ./libft/ft_isdigit.c ./libft/ft_strncmp.c ./libft/ft_split.c ./libft/ft_strlen.c \
		./libft/ft_isalpha.c ./libft/ft_printf.c ./libft/ft_putnbr_fd.c ./libft/ft_putnbr_fd_u.c \
		./libft/ft_putstr_fd.c ./libft/intohex.c ./libft/ft_putchar_fd.c ./libft/ft_malloc.c ./instructions/swap.c ./instructions/push.c \
		./instructions/rotate.c ./instructions/reverse_rotate.c ./algo/algo.c ./utils/check.c ./utils/helper.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(NAME).c $(OBJ) -o $(NAME)

%.o: %.c ../libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME) $(BONUS)
	rm -rf push_swap.dSYM

re: fclean all

.PHONY: clean
