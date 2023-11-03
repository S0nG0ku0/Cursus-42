/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:04:21 by ohaida            #+#    #+#             */
/*   Updated: 2023/10/30 12:14:15 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	lowercase;
	int	uppercase;

	lowercase = (c >= 97 && c <= 122);
	uppercase = (c >= 65 && c <= 90);
	if ((lowercase || uppercase))
		return (1);
	return (0);
}
