/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:36:43 by ohaida            #+#    #+#             */
/*   Updated: 2024/05/15 16:19:33 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include "ft_printf.h"

int			ft_isdigit(int c);
long long	ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(char *s, char c);
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
void		check(char **tab);
void		check_duplicates(int *numArray, int count);
int			*convert_tab_to_int_array(char **tab, int *count);
void		pivoting(int *a, int *b, int *count_a, int *count_b);
void		indexing(int *num, int *count);
void		algo(int *a, int *b, int *count_a, int *count_b);
void		issorted(int *num, int count);
int			issortedv2(int *num, int count);
void		check_empty_arg(char **temp, char **argv, int *i);
void		check_to_numbers(int count_a, int *a);
void		sort_three_numbers(int *a, int *count_a);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif