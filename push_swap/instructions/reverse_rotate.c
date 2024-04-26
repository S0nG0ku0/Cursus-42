/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:21:09 by ohaida            #+#    #+#             */
/*   Updated: 2024/04/26 21:06:07 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void	reverse_rotate(int *num, int count)
{
	int	i;
	int	*tmp;

	tmp = (int *)ft_malloc(count * sizeof(int *), 0);
	i = 0;
	while (i < count)
	{
		tmp[i] = num[i];
		i++;
	}
	i = 0;
	while (i < count)
	{
		num[i] = tmp[i - 1];
		i++;
	}
	num[0] = tmp[count - 1];
}

void	reverse_rotate_a(int *num, int count)
{
	reverse_rotate(num, count);
	ft_printf("rra\n");
}

void	reverse_rotate_b(int *num, int count)
{
	reverse_rotate(num, count);
	ft_printf("rrb\n");
}

void	reverse_rotate_a_b(int *a, int *b, int count_a, int count_b)
{
	reverse_rotate(a, count_a);
	reverse_rotate(b, count_b);
	ft_printf("rrr\n");
}
