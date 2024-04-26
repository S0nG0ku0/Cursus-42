/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:26:53 by ohaida            #+#    #+#             */
/*   Updated: 2024/04/26 21:50:45 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void	rotate(int *num, int count)
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = ft_malloc(count * sizeof(int *), 0);
	while (i < count)
	{
		tmp[i] = num[i];
		i++;
	}
	i = 0;
	while (i < count)
	{
		num[i] = tmp[i + 1];
		i++;
	}
	num[count - 1] = tmp[0];
}

void	rotate_a(int *num, int count)
{
	rotate(num, count);
	ft_printf("ra\n");
}

void	rotate_b(int *num, int count)
{
	rotate(num, count);
	ft_printf("rb\n");
}

void	rotate_a_b(int *a, int *b, int count_a, int count_b)
{
	rotate(a, count_a);
	rotate(b, count_b);
	ft_printf("rr\n");
}
