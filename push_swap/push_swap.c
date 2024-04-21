/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:33:14 by ohaida            #+#    #+#             */
/*   Updated: 2024/04/21 10:36:03 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	push_swap(int *numarray, int count_a)
{
	int	count_b;
	int	*a;
	int	*b;
	int	i;

	count_b = 0;
	i = 0;
	a = malloc(sizeof(int) * count_a);
	b = malloc(sizeof(int) * count_a);
	while (i < count_a)
	{
		a[i] = numarray[i];
		i++;
	}
	indexing(a, &count_a);
}

char	**ft_concat_arrays(char **arr1, char **arr2)
{
	int		i;
	int		j;
	int		k;
	char	**result;

	i = 0;
	j = 0;
	while (arr1[i] != NULL)
		i++;
	while (arr2[j] != NULL)
		j++;
	result = ft_malloc((i + j + 1) * sizeof(char *), 0);
	if (result == NULL)
		return (NULL);
	k = 0;
	while (k < i)
	{
		result[k] = arr1[k];
		k++;
	}
	k = 0;
	while (k < j)
	{
		result[i + k] = arr2[k];
		k++;
	}
	result[i + j] = NULL;
	return (result);
}

int	main(int argc, char **argv)
{
	int		i;
	int		count_a;
	char	**tab;
	char	**temp;
	int		*numArray;

	i = 1;
	count_a = 0;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		if (tab == NULL)
		{
			tab = temp;
		}
		else
		{
			tab = ft_concat_arrays(tab, temp);
		}
		i++;
	}
	check(tab);
	numArray = convert_tab_to_int_array(tab, &count_a);
	check_duplicates(numArray, count_a);
	push_swap(numArray, count_a);
	ft_malloc(0, 1);
}
