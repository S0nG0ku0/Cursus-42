/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:36:43 by ohaida            #+#    #+#             */
/*   Updated: 2024/04/19 16:38:59 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf.h"

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
long long	ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_bzero(void *s, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dest, char *src, size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		**ft_split(char *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		*ft_malloc(int size, int bool_free);
void		swap_a(int *num, int count);
void		swap_b(int *num, int count);
void		ss(int *num_a, int *num_b, int count_a, int count_b);
void		push_a(int *a, int *b, int *count_a, int *count_b);
void		push_b(int *a, int *b, int *count_a, int *count_b);
void		rotate_a(int *num, int count);
void		rotate_b(int *num, int count);
void		rotate_a_b(int *a, int *b, int count_a, int count_b);
void		reverse_rotate_a(int *num, int count);
void		reverse_rotate_b(int *num, int count);
void		reverse_rotate_a_b(int *a, int *b, int count_a, int count_b);
char		**ft_concat_arrays(char **arr1, char **arr2);
void		check(char **tab);
void		check_duplicates(int *numArray, int count);
int			*convert_tab_to_int_array(char **tab, int *count);
void		pivoting(int *a, int *b, int *count_a, int *count_b);
void		sort_method(int *a, int *count_a);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif