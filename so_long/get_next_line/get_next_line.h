/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:39:01 by ohaida            #+#    #+#             */
/*   Updated: 2024/01/23 17:39:02 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_rest(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_getleast(char *b);
char	*ft_gettext(char *b);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif