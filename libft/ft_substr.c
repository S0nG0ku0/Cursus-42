/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:31:17 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/03 17:03:57 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	alloc_mem(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	if (len > s_len)
		return (s_len - start);
	if (s_len > len)
		return (len);
	return (len - start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s[0] == '\0' || start >= ft_strlen(s))
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
	str = malloc(alloc_mem(s, start, len) + 1);
	if (str == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str); 
}
