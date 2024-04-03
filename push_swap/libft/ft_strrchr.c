/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:08:31 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/03 21:08:27 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				j;
	unsigned char	x;

	i = 0;
	x = c;
	j = -1;
	while (s[i])
	{
		if (s[i] == x)
			j = i;
		i++;
	}
	if (j != -1)
		return ((char *)&s[j]);
	if (x == 0)
		return ((char *)&s[i]);
	return (NULL);
}
