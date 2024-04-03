/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:49:18 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/19 19:51:51 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int nb, int fd)
{
	int	res;

	res = 0;
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
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
