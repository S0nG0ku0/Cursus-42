/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:33:14 by ohaida            #+#    #+#             */
/*   Updated: 2024/05/03 17:01:35 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

static void	helper(char **result, char **arr1, int *i)
{
	int	k;

	k = 0;
	while (k < *i)
	{
		result[k] = arr1[k];
		k++;
	}
}

void	push_swap(int *numarray, int count_a)
{
	int	count_b;
	int	*a;
	int	*b;
	int	i;

	count_b = 0;
	i = 0;
	a = ft_malloc(sizeof(int *) * count_a, 0);
	if (!a)
		exit(1);
	b = ft_malloc(sizeof(int *) * count_a, 0);
	if (!b)
	{
		free(a);
		exit(1);
	}
	while (i < count_a)
	{
		a[i] = numarray[i];
		i++;
	}
	indexing(a, &count_a);
	algo(a, b, &count_a, &count_b);
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
	if (!result)
		exit(1);
	helper(result, arr1, &i);
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
	int		*numarray;

	i = 1;
	count_a = 0;
	if (argc < 2)
		exit(0);
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		if (tab == NULL)
			tab = temp;
		else
			tab = ft_concat_arrays(tab, temp);
		i++;
	}
	check(tab);
	numarray = convert_tab_to_int_array(tab, &count_a);
	check_duplicates(numarray, count_a);
	push_swap(numarray, count_a);
	ft_malloc(0, 1);
}
