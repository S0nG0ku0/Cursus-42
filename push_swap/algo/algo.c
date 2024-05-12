/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:26:20 by ohaida            #+#    #+#             */
/*   Updated: 2024/05/12 22:39:58 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <strings.h>

static int	get_index(int *a, int *b, int *count_b)
{
	int	i;

	i = 0;
	while (i < *count_b)
	{
		if (b[i] == a[0] - 1)
			return (i);
		i++;
	}
	return (-1);
}

static void	push_to_a(int *a, int *b, int *count_a, int *count_b)
{
	int	i;
	int	index;

	i = 0;
	while (i < *count_b)
	{
		if (b[i] == a[0] - 1)
			index = i;
		if (index == 0)
			push_a(a, b, count_a, count_b);
		index = 1;
		i++;
	}
}

static void	with_index(int *a, int *b, int *count_a, int *count_b)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	push_to_a(a, b, count_a, count_b);
	sort_three_numbers(a, count_a);
	while (*count_b)
	{
		if (get_index(a, b, count_b) > *count_b / 2)
		{
			reverse_rotate_b(b, *count_b);
			push_to_a(a, b, count_a, count_b);
		}
		else if (get_index(a, b, count_b) <= *count_b / 2)
		{
			rotate_b(b, *count_b);
			push_to_a(a, b, count_a, count_b);
		}
	}
}

static void	helper(int count_a, int *p1, int *p2, int *pl)
{
	*pl = *p1;
	*p1 = (count_a / 3) + *pl;
	*p2 = (count_a / 6) + *pl;
}

void	algo(int *a, int *b, int *count_a, int *count_b)
{
	int	p1;
	int	p2;
	int	pl;
	int	count;

	count = *count_a;
	pl = 0;
	p1 = (*count_a / 3) + pl;
	p2 = (*count_a / 6) + pl;
	while (*count_a > 3)
	{
		if (count == 4 && a[0] < p1)
			push_b(a, b, count_a, count_b);
		if (count > 4 && a[0] <= p1)
			push_b(a, b, count_a, count_b);
		else
			rotate_a(a, *count_a);
		if ((b[0] <= p2 && b[0] >= pl) && *count_b > 0)
			rotate_b(b, *count_b);
		if (*count_b > p1)
			helper(*count_a, &p1, &p2, &pl);
	}
	with_index(a, b, count_a, count_b);
}
