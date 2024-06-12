SRC = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./checker/checker.c so_long.c \
		./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c \
		./libft/ft_printf.c ./libft/ft_putnbr_fd.c ./libft/ft_putnbr_fd_u.c \
		./libft/ft_atoi.c ./libft/ft_isdigit.c \
		./libft/ft_strncmp.c ./libft/ft_strlen.c \
		./libft/intohex.c  ./libft/ft_malloc.c ./libft/ft_strdup.c ./checker/floodfill.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean