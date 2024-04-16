/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:16:03 by ohaida            #+#    #+#             */
/*   Updated: 2024/04/16 15:06:29 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last;

	if (!new_node || !lst)
		return ;
	if (*lst == NULL)
	{
	ft_printf("x");
		*lst = new_node;
		return ;
	}
	ft_printf("x");
	last = ft_lstlast(*lst);
	last->next = new_node;
}
