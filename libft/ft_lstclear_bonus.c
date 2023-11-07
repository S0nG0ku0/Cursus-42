/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:16:33 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/07 22:16:37 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (!lst || !del)
		return ;
	while ((*lst))
	{
		del((*lst)->content);
		tmp = (*lst);
		(*lst) = (*lst)->next;
		free(tmp);
	}
}
