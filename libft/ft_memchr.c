/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:20:37 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/09 10:53:16 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		x;

	i = 0;
	str = s;
	x = (unsigned char *)c;
	while (i < n)
	{
		if (str[i] == x)
			return ((unsigned char *)&s[i]);
		i++;
	}
	return (0);
}
