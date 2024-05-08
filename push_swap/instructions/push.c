/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:16:50 by ohaida            #+#    #+#             */
/*   Updated: 2024/05/03 17:24:12 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void	push(int *num1, int *num2, int *count_1, int *count_2)
{
	int	i;

	if (*count_1 == 0)
		return ;
	i = *count_2;
	while (i > 0)
	{
		num2[i] = num2[i - 1];
		i--;
	}
	num2[0] = num1[0];
	i = 0;
	while (i < *count_1 - 1)
	{
		num1[i] = num1[i + 1];
		i++;
	}
	(*count_1)--;
	(*count_2)++;
}

void	push_a(int *a, int *b, int *count_a, int *count_b)
{
	push(b, a, count_b, count_a);
	ft_printf("pa\n");
}

void	push_b(int *a, int *b, int *count_a, int *count_b)
{
	push(a, b, count_a, count_b);
	ft_printf("pb\n");
}
