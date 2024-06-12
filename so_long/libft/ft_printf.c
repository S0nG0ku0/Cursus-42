/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:34:00 by ohaida            #+#    #+#             */
/*   Updated: 2023/12/11 10:05:01 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_value(char c, va_list args, int res)
{
	if (c == 'd' || c == 'i')
		res += ft_putnbr_fd(va_arg(args, int), 1);
	if (c == 'u')
		res += ft_putnbr_fd_u(va_arg(args, int), 1);
	if (c == 'c')
		res += ft_putchar_fd(va_arg(args, int), 1);
	return (res);
}

static int	coll(int res, char c, va_list args)
{
	if (c == 'd' || c == 'i' || c == 'c' | c == 'u')
		res = int_value(c, args, res);
	else if (c == 'x' || c == 'X')
		res += intohex(va_arg(args, unsigned int), c);
	else if (c == 's')
		res += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
	{
		res += ft_putstr_fd("0x", 1);
		res += intohex(va_arg(args, unsigned long), c);
	}
	else if (c == '%')
		res += ft_putchar_fd('%', 1);
	else if (c != '\0')
		res += ft_putchar_fd(c, 1);
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			res = coll(res, str[i], args);
		}
		else
			res += ft_putchar_fd(str[i], 1);
		if (str[i])
			i++;
	}
	va_end(args);
	return (res);
}
