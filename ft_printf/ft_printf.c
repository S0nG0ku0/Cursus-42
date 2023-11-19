/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:34:00 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/19 20:34:53 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_value(char c, int intvalue, va_list args, int res)
{
	if (c == 'd' || c == 'i')
	{
		intvalue = va_arg(args, int);
		res += ft_putnbr_fd(intvalue, 1);
	}
	if (c == 'u')
	{
		intvalue = va_arg(args, int);
		res += ft_putnbr_fd_u(intvalue, 1);
	}
	if (c == 'c')
	{
		intvalue = va_arg(args, int);
		res += ft_putchar_fd(intvalue, 1);
	}
	return (res);
}

static int	coll(int res, char c, va_list args)
{
	char	*value;
	int		intvalue;

	intvalue = 0;
	if (c == 'd' || c == 'i' || c == 'c' | c == 'u')
		res = int_value(c, intvalue, args, res);
	else if (c == 'x' || c == 'X')
		res += intohex(va_arg(args, unsigned int), c);
	else if (c == 's')
	{
		value = va_arg(args, char *);
		res += ft_putstr_fd(value, 1);
	}
	else if (c == 'p')
	{
		res += ft_putstr_fd("0x", 1);
		res += intohex(va_arg(args, unsigned long), c);
	}
	else if (c == '%')
		res += ft_putchar_fd('%', 1);
	else
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
