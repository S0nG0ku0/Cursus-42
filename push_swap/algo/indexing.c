/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:15:37 by ohaida            #+#    #+#             */
/*   Updated: 2024/05/08 22:53:35 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>

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

	sorting = ft_malloc(*count * sizeof(int *), 0);
	if (!sorting)
		exit(1);
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
}

void	issorted(int *num, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (num[i] > num[i + 1])
			return ;
		i++;
	}
	exit(0);
}

int	issortedv2(int *num, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (num[i] > num[i + 1])
			return (1);
		i++;
	}
	return(0);
}
