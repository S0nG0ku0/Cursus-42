/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:28:57 by ohaida            #+#    #+#             */
/*   Updated: 2023/12/15 19:50:20 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <libc.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct arg
{
	ssize_t	bytes_read;
	char	*b;
	char	*tmp;
	char	*line;
	int		i;
}	t_arg;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_getleast(char *b);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);

#endif