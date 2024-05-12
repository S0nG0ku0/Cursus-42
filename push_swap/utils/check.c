/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:12:22 by ohaida            #+#    #+#             */
/*   Updated: 2024/05/12 22:37:48 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void	check_2(int count, char **tab, int *i)
{
	if (count >= 1 || ((tab[*i][0] == '+' || tab[*i][0] == '-')
		&& !ft_isdigit(tab[*i][1])))
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (ft_strlen(tab[*i]) > 52)
	{
		ft_printf("Error\n");
		exit(1);
	}
}

void	check(char **tab)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		count = 0;
		if (tab[i][0] == '+' || tab[i][0] == '-')
			j++;
		while (tab[i][j] != '\0')
		{
			if (!ft_isdigit(tab[i][j]))
				count++;
			j++;
		}
		check_2(count, tab, &i);
		i++;
	}
}

void	check_duplicates(int *numArray, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numArray[i] == numArray[j])
			{
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_empty_arg(char **temp, char **argv, int *i)
{
	if (!temp || !temp[0] || argv[*i][0] == '\0')
	{
		ft_printf("Error\n");
		exit(1);
	}
}

void	check_to_numbers(int count_a, int *a)
{
	if (count_a == 2)
	{
		if (issortedv2(a, count_a))
		{
			swap_a(a, count_a);
			exit(0);
		}
		else
			return ;
	}
}
