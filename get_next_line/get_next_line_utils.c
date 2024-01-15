/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:34:16 by ohaida            #+#    #+#             */
/*   Updated: 2024/01/11 15:42:19 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gettext(char *line)
{
	char	*res;
	int		i;

	i = 0;
	if (!line || !*line)
		return (free(line), line = NULL, NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (!ft_strchr(line, '\n'))
		i--;
	res = malloc(i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		res[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		res[i++] = '\n';
	res[i] = 0;
	return (res);
}

char	*ft_strchr(char *s, int c)
{
	int				i;
	unsigned char	x;

	i = 0;
	x = c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == x)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_getleast(char *b)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = NULL;
	i = 0;
	j = 0;
	while (b[i] != '\0' && b[i] != '\n')
		i++;
	if (b[i] == '\n')
		i++;
	tmp = malloc(ft_strlen(b) - i + 1);
	if (!tmp)
		return (free(b), b = NULL, NULL);
	while (b[i] != '\0')
	{
		tmp[j] = b[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	(free(b), b = NULL);
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (free(s1), NULL);
	while (s1[++i])
		res[i] = s1[i];
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = 0;
	free(s1);
	return (res);
}
