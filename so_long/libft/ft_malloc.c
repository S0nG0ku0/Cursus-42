/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:58:41 by ohaida            #+#    #+#             */
/*   Updated: 2024/05/15 19:32:10 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(t_list *all_alloc)
{
	t_list	*tmp;

	while (all_alloc)
	{
		free(all_alloc->content);
		tmp = all_alloc;
		all_alloc = all_alloc->next;
		free(tmp);
	}
}

static int	add_node(t_list *all_alloc, void *ptr)
{
	while (all_alloc->next)
		all_alloc = all_alloc->next;
	all_alloc->next = malloc(sizeof(t_list));
	if (!all_alloc->next)
		return (1);
	all_alloc->next->content = ptr;
	all_alloc->next->next = NULL;
	return (0);
}

void	*ft_malloc(int size, int free)
{
	static t_list	all_alloc = {"head", NULL};
	void			*ptr;

	ptr = NULL;
	if (free)
	{
		free_all(all_alloc.next);
		all_alloc.next = NULL;
		return (NULL);
	}
	ptr = malloc(size);
	if (!ptr || add_node(&all_alloc, ptr))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (ptr);
}
