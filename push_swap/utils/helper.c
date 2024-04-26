/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:09:39 by ohaida            #+#    #+#             */
/*   Updated: 2024/04/26 21:08:36 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	*convert_tab_to_int_array(char **tab, int *count)
{
	char	**tabptr;
	int		tabsize;
	int		*numarray;
	int		i;

	tabptr = tab;
	tabsize = 0;
	while (*tabptr)
	{
		tabsize++;
		tabptr++;
	}
	numarray = (int *)ft_malloc(sizeof(int *) * (tabsize), 0);
	if (!numarray)
		return (NULL);
	tabptr = tab;
	i = 0;
	while (*tabptr)
	{
		numarray[i] = ft_atoi(*tabptr);
		i++;
		tabptr++;
	}
	*count = i;
	return (numarray);
}
