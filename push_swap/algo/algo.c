/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:26:20 by ohaida            #+#    #+#             */
/*   Updated: 2024/04/21 20:12:26 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void	helper(int *sorting, int *count, int *temp, int *num)
{
	int	i;
	int	j;

	i = 0;
	while (i < *count)
	{
		sorting[i] = num[i];
		i++;
	}
	i = 0;
	while (i < *count)
	{
		j = i + 1;
		while (j < *count)
		{
			if (sorting[i] > sorting[j])
			{
				*temp = sorting[i];
				sorting[i] = sorting[j];
				sorting[j] = *temp;
			}
			j++;
		}
		i++;
	}
}

void	indexing(int *num, int *count)
{
	int	i;
	int	j;
	int	*sorting;
	int	temp;

	sorting = malloc(*count * sizeof(int));
	temp = 0;
	helper(sorting, count, &temp, num);
	i = 0;
	while (i < *count)
	{
		j = 0;
		while (j < *count)
		{
			if (num[i] == sorting[j])
			{
				num[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	i = 0;
	free(sorting);
}

void	algo(int *a, int *b, int *count_a, int *count_b)
{
	int	p1;
	int	p2;
	int	pl;
	int	i;

	pl = 0;
	p1 = (*count_a / 3) + pl;
	p2 = (*count_a / 6) + pl;

	i = 0;
	while (i < *count_a)
	{
		ft_printf("a[%i]: %d\n", i, a[i]);
		i++;
	}
	i = 0;
	ft_printf("p1: %d\np2: %d\n", p1, p2);
	while (*count_a > 3)
	{
		if (a[0] <= p1)
			push_b(a, b, count_a, count_b);
		else
			rotate_a(a, *count_a);
		if ((b[0] <= pl && b[0] >= p2) && *count_b > 0)
			rotate_b(b, *count_b);
		if (*count_b > p1)
		{
			pl = p1;
			p1 = (*count_a / 3) + pl;
			p2 = (*count_a / 6) + pl;
		}
	}
	i = 0;
	while (i < *count_a)
	{
		ft_printf("a[%i]: %d\n", i, a[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < *count_b)
	{
		ft_printf("b[%i]: %d\n", i, b[i]);
		i++;
	}
}
