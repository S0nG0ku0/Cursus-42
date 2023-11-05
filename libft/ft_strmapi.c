/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:18:32 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/05 19:39:18 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*r;
	int		i;

	if (!s || !f)
		return (NULL);
	r = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (r == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		r[i] = f(i, *s);
		i++;
		s++;
	}
	return (r);
}
