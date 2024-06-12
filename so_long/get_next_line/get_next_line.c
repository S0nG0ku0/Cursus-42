/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:38:54 by ohaida            #+#    #+#             */
/*   Updated: 2024/06/10 17:50:08 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*gn_strdup(const char *s1)
{
	int			i;
	size_t		len;
	char		*str;

	i = 0;
	len = gn_strlen(s1);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*gn_read(int fd, char *str)
{
	char	*buff;
	int		readed;

	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (free(str), str = NULL, NULL);
	readed = 1;
	while (!gn_strchr(str, '\n') && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		buff[readed] = '\0';
		if (readed == -1)
			return (free(buff), NULL);
		str = gn_strjoin(str, buff);
	}
	free(buff);
	if (!str || !*str)
		return (free(str), str = NULL, NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	line = 0;
	if (BUFFER_SIZE <= 0
		|| read(fd, 0, 0) == -1 || BUFFER_SIZE > INT_MAX)
		return (free(buffer), buffer = NULL, NULL);
	buffer = gn_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = gn_gettext(buffer);
	if (!line)
		return (free (buffer), buffer = NULL, NULL);
	buffer = gn_getleast(buffer);
	return (line);
}
