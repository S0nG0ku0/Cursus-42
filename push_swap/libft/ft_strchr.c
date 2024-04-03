/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:22:34 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/01 19:47:36 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	x;

	i = 0;
	x = c;
	while (s[i])
	{
		if (s[i] == x)
			return ((char *)&s[i]);
		i++;
	}
	if (x == 0)
	{
		return ((char *)&s[i]);
	}
	return (0);
}
