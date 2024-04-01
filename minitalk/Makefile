SRC = ./src/ft_putchar_fd.c ./src/ft_atoi.c ./src/ft_putnbr_fd.c
OBJ = $(SRC:.c=.o)

NAME_SERVER = server
NAME_CLIENT = client
CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(NAME_SERVER).c $(OBJ)
	$(CC) $(CFLAGS) $(NAME_SERVER).c -o $(NAME_SERVER) $(OBJ)

$(NAME_CLIENT): $(NAME_CLIENT).c $(OBJ)
	$(CC) $(CFLAGS) $(NAME_CLIENT).c -o $(NAME_CLIENT) $(OBJ)

%.o: ./src/%.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_SERVER)_bonus $(NAME_CLIENT)_bonus

$(NAME_SERVER)_bonus: $(NAME_SERVER)_bonus.c $(OBJ)
	$(CC) $(CFLAGS) $(NAME_SERVER)_bonus.c -o $(NAME_SERVER)_bonus $(OBJ)

$(NAME_CLIENT)_bonus: $(NAME_CLIENT)_bonus.c $(OBJ)
	$(CC) $(CFLAGS) $(NAME_CLIENT)_bonus.c -o $(NAME_CLIENT)_bonus $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_CLIENT)_bonus $(NAME_SERVER)_bonus

re: fclean all

.PHONY: all clean fclean re