SRC = ./src/ft_putchar_fd.c ./src/ft_atoi.c ./src/ft_putnbr_fd.c
OBJ = $(SRC:.c=.o)

NAME_SERVER = server
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT = client
NAME_CLIENT_BONUS = client_bonus
CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(NAME_SERVER).c $(OBJ)
	$(CC) $(CFLAGS) $(NAME_SERVER).c -o $(NAME_SERVER) $(OBJ)

$(NAME_CLIENT): $(NAME_CLIENT).c $(OBJ)
	$(CC) $(CFLAGS) $(NAME_CLIENT).c -o $(NAME_CLIENT) $(OBJ)

%.o: ./src/%.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(NAME_SERVER_BONUS).c $(OBJ)
	$(CC) $(CFLAGS) $(NAME_SERVER_BONUS).c -o $(NAME_SERVER_BONUS) $(OBJ)

$(NAME_CLIENT_BONUS): $(NAME_CLIENT_BONUS).c $(OBJ)
	$(CC) $(CFLAGS) $(NAME_CLIENT_BONUS).c -o $(NAME_CLIENT_BONUS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re