/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:50:20 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/02 10:03:38 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s2_l;
	const unsigned char	*s1_l;

	i = 0;
	s1_l = (const unsigned char *)s1;
	s2_l = (const unsigned char *)s2;
	while (i < n)
	{
		if (s1_l[i] != s2_l[i])
			return (s1_l[i] - s2_l[i]);
		i++;
	}
	return (0);
}
