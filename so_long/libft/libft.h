/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:36:43 by ohaida            #+#    #+#             */
/*   Updated: 2024/06/13 02:19:07 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_map
{
	int x;
	int c;
	int e;
	int y;
	int moves;
	int player_x;
	int player_y;
	int player;
	int coins;
	int exit;
	char **map;
	char **copy;
} t_map;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_map	*map;
	char	*path;
}				t_vars;

char		*get_next_line(int fd);
char		*gn_rest(char *buffer);
char		*gn_strjoin(char *s1, char *s2);
char		*gn_getleast(char *b);
char		*gn_gettext(char *b);
char		*gn_strchr(char *s, int c);
char		*gn_strdup(const char *s1);
char		*ft_strdup(const char *s1);
size_t		gn_strlen(const char *s);
int			ft_isdigit(int c);
long long	ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		slchecker_wall(t_map *map);
char		**ft_split(char *s, char c);
void		*ft_malloc(int size, int bool_free);
int			ft_printf(const char *str, ...);
int			ft_putstr_fd(char *s, int fd);
int			ft_putnbr_fd(int nb, int fd);
int			ft_putchar_fd(char c, int fd);
int			intohex(unsigned long number, char c);
int			ft_putnbr_fd_u(unsigned int nb, int fd);
int 		all_reach(t_map *map);
void		copy_map(t_map *map);

#endif