/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:02:47 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/07 20:20:04 by ohaida           ###   ########.fr       */
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
