/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:16:50 by ohaida            #+#    #+#             */
/*   Updated: 2024/04/19 11:02:22 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void	return_temp(int *temp, int *num, int *count)
{
	int	i;

	i = 0;
	while (i < *count)
	{
		temp[i] = num[i];
		i++;
	}
}

static void	push(int *num1, int *num2, int *count_1, int *count_2)
{
	int	i;
	int	*temp;

	temp = malloc(*count_1);
	if (count_1 == 0)
		return ;
	return_temp(temp, num1, count_1);
	num2[0] = num1[0];
	i = 0;
	(*count_1)--;
	while (i < *count_1)
	{
		num1[i] = num1[i + 1];
		i++;
	}
	i = 0;
	(*count_2)++;
	while (i < *count_2)
	{
		num2[i + 1] = temp[i];
		i++;
	}
	free(temp);
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
