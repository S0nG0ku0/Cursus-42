/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:35:25 by ohaida            #+#    #+#             */
/*   Updated: 2023/12/15 19:50:12 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;
	unsigned char	*str;

	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	alloc = (void *)malloc(count * size);
	if (alloc == NULL)
		return (NULL);
	ft_memset(alloc, '\0', count * size);
	return (alloc);
}

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
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
	tmp = ft_calloc(ft_strlen(b) - i + 1, 1);
	while (b[i] != '\0')
	{
		tmp[j] = b[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	free(b);
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	str = calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	(free(s1), free(s2));
	return (str);
}
