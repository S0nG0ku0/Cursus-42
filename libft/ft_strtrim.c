/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:21:10 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/08 14:43:00 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (set[i])
	{
		if (set[i] == c)
			x = 1;
		i++;
	}
	return (x);
}

static int	set_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (set == NULL)
		return (0);
	while (s1[i] && is_set(s1[i], set))
		i++;
	return (i);
}

static int	set_end(char const *s1, char const *set)
{
	size_t	len;

	len = ft_strlen(s1);
	if (set == NULL)
		return (ft_strlen(s1));
	while (len > 0 && is_set(s1[len - 1], set))
		len--;
	if (len <= 0)
		return (ft_strlen(s1));
	return (len - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	start = set_start(s1, set);
	end = set_end(s1, set);
	if (set == NULL)
		str = malloc(ft_strlen(s1) + 1);
	else
		str = malloc((end - start) + 2);
	if (str == NULL)
		return (NULL);
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
