/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:54:31 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/19 19:55:28 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_u(unsigned int nb, int fd)
{
	int	res;

	res = 0;
	if (nb < 0)
	{
		res += ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
	{
		res += ft_putnbr_fd(nb / 10, fd);
	}
	res += ft_putchar_fd('0' + nb % 10, fd);
	return (res);
}
