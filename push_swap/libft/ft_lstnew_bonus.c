/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:16:53 by ohaida            #+#    #+#             */
/*   Updated: 2023/12/16 21:53:10 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
#include <stdio.h>
#include "libft.h"

int main()
{
   	t_list *head = NULL;
    t_list *temp = NULL;
    size_t i;
	size_t c;

    for(i = 5; i > 0; i--)
    {
        temp = ft_lstnew(i);
        temp->next = head;
        head = temp;
    }
    temp = head;
    while(temp != NULL)
    {
        printf("%zu\n", (size_t)temp->content);
        temp = temp->next;
    }
}