/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:51:28 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/02 09:53:30 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s2_l;
	const unsigned char	*s1_l;

	i = 0;
	s1_l = (const unsigned char *)s1;
	s2_l = (const unsigned char *)s2;
	while ((s1_l[i] || s2_l[i]) && i < n)
	{
		if (s1_l[i] != s2_l[i])
			return (s1_l[i] - s2_l[i]);
		i++;
	}
	return (0);
}
