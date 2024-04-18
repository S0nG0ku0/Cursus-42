/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:58:16 by ohaida            #+#    #+#             */
/*   Updated: 2024/04/18 16:32:30 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isoverflow(long long a, long long b)
{
	long long	result;

	if (a == 0 || b == 0)
		return (0);
	result = a * b;
	if (a == result / b)
		return (0);
	else
		return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	if (isoverflow(count, size))
		return (NULL);
	alloc = (void *)malloc(count * size);
	if (alloc == NULL)
		return (NULL);
	ft_bzero(alloc, count * size);
	return (alloc);
}
