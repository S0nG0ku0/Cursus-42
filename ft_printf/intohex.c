/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intohex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:52:28 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/19 20:10:45 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	intohex(unsigned long number, char c)
{
	int				res;
	unsigned long	x;
	unsigned long	remainder;

	res = 0;
	if (number < 16)
	{
		remainder = number % 16;
		if (remainder < 10)
			x = remainder + '0';
		else
		{
			if (c == 'x' || c == 'p')
				x = remainder + 'a' - 10;
			if (c == 'X')
				x = remainder + 'A' - 10;
		}
		res += ft_putchar_fd(x, 1);
		return (res);
	}
	res += intohex(number / 16, c);
	res += intohex(number % 16, c);
	return (res);
}
