/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:26:20 by ohaida            #+#    #+#             */
/*   Updated: 2024/04/26 20:32:03 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <strings.h>

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

static void	sort_three_numbers(int *a, int *count_a)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < *count_a)
	{
		j = i + 1;
		while (j < *count_a)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			j++;
		}
		i++;
	}
}

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
	int index;

	i = 0;
	*count_a = *count_a;
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
	int i;
	int index;

	i = 0;
	index = 0;
	sort_three_numbers(a, count_a);
	push_to_a(a, b, count_a, count_b);
	while (*count_b)
    {
        if (get_index(a, b, count_b) > *count_b / 2)
		{
            reverse_rotate_b(b, *count_b);
			push_to_a(a, b, count_a, count_b);
		}
		else
		{
			rotate_b(b, *count_b);
			push_to_a(a, b, count_a, count_b);
		}
    }
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
	with_index(a, b, count_a, count_b);
}
