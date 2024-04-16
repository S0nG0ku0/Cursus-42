/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:16:33 by ohaida            #+#    #+#             */
/*   Updated: 2024/04/16 15:22:42 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(t_list *))
{
	t_list	*tmp;

	while (!lst || !del)
		return ;
	while ((*lst))
	{
		ft_printf("----> %p %p %p\n", (*lst), (*lst)->content , tmp);
		del((*lst)->content);
		tmp = (*lst);
		(*lst) = (*lst)->next;
		free(tmp);
	}
}
