/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:38:24 by ohaida            #+#    #+#             */
/*   Updated: 2024/02/02 08:33:35 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	int			i;
	size_t		len;
	char		*str;

	i = 0;
	len = ft_strlen(s1);
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

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		readed;

	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (free(str), str = NULL, NULL);
	readed = 1;
	while (!ft_strchr(str, '\n') && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		buff[readed] = '\0';
		if (readed == -1)
			return (free(buff), NULL);
		str = ft_strjoin(str, buff);
	}
	free(buff);
	if (!str || !*str)
		return (free(str), str = NULL, NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[OPEN_MAX];

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (BUFFER_SIZE <= 0
		|| read(fd, 0, 0) == -1 || BUFFER_SIZE > INT_MAX)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_gettext(buffer[fd]);
	if (!line)
		return (free (buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = ft_getleast(buffer[fd]);
	return (line);
}
