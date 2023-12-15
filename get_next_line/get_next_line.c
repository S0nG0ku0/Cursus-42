/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:35:18 by ohaida            #+#    #+#             */
/*   Updated: 2023/12/15 15:30:09 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*allocate_memory(char *line, char *b)
{
	char	*tmp;

	tmp = calloc(ft_strlen(line) + ft_strlen(b) + 1, 1);
	tmp[ft_strlen(line) + ft_strlen(b)] = '\0';
	return (tmp);
}

int	copy_to_tmp(char *line, char *b, char *tmp)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (line[i] != '\0')
	{
		tmp[k] = line[i];
		i++;
		k++;
	}
	i = 0;
	while (b[i] != '\0' && b[i] != '\n')
	{
		tmp[k] = b[i];
		i++;
		k++;
	}
	if (b[i] == '\n')
		tmp[k] = '\n';
	return (i);
}

char	*handle_eof_or_line(char *tmp, char *b)
{
	free(tmp);
	tmp = NULL;
	free(b);
	b = NULL;
	return (NULL);
}

char	*aaa(t_arg *arg, char **rest, int fd)
{
	while (arg->bytes_read > 0)
	{
		arg->b = (char *)calloc((size_t)BUFFER_SIZE + 1, 1);
		arg->bytes_read = read(fd, arg->b, BUFFER_SIZE);
		arg->b[BUFFER_SIZE] = '\0';
		if (*rest)
		{
			arg->b = ft_strjoin(*rest, arg->b);
			*rest = NULL;
		}
		arg->tmp = allocate_memory(arg->line, arg->b);
		arg->i = copy_to_tmp(arg->line, arg->b, arg->tmp);
		free(arg->line);
		arg->line = arg->tmp;
		if ((arg->b)[arg->i] == '\n' || arg->bytes_read == 0)
		{
			if (arg->bytes_read == 0 && *(arg->line) == '\0')
				return (handle_eof_or_line(arg->tmp, arg->b));
			*rest = ft_getleast(arg->b);
			break ;
		}
		(free(arg->b), arg->b = NULL);
	}
	return (arg->line);
}

char	*get_next_line(int fd)
{
	static char		*rest;
	t_arg			arg;

	arg.i = 0;
	arg.tmp = NULL;
	arg.b = NULL;
	arg.bytes_read = 1;
	if (fd < 0 || fd >= OPEN_MAX
		|| BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(rest), NULL);
	arg.line = malloc(1);
	*(arg.line) = '\0';
	return (aaa(&arg, &rest, fd));
}
