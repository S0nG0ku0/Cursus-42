SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJ = $(SRC:.c=.o)
SRCB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c
OBJB = $(SRCB:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
NAME = libft.a

all: $(NAME)

bonus: all $(OBJB)
	$(AR) $(NAME) $(OBJB)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(BONUS): $(OBJB)
	$(AR) $(NAME) $(OBJB)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY:	all clean fclean re