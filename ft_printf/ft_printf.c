/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:34:00 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/19 13:23:33 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}


size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}

int intToHex(unsigned long number, char c)
{
	unsigned long x;
	unsigned long remainder;
	int res = 0;
	
    if (number < 16)
    {
		// if (c == 'p')
		// 	res += ft_putstr_fd("/x", 1);
        remainder = number % 16; //123456789
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
    // remainder = number % 16;
    res += intToHex(number / 16, c);
    res += intToHex(number % 16, c);
	return (res);
}

int ft_putnbr_fd(int nb, int fd)
{
	int res = 0;
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

int ft_putnbr_fd_u(unsigned int nb, int fd)
{
	int res = 0;
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

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		res;
	char	*value;
	int		intValue;

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
			if (str[i] == 'd' || str[i] == 'i')
			{
				intValue = va_arg(args, int);
				res += ft_putnbr_fd(intValue, 1);
			}
			if (str[i] == 'u')
			{
				intValue = va_arg(args, int);
				res += ft_putnbr_fd_u(intValue, 1);
			}
			if (str[i] == 'c')
			{
				intValue = va_arg(args, int);
				res += ft_putchar_fd(intValue, 1);
			}
			if (str[i] == 's')
			{
				value = va_arg(args, char *);
				res += ft_putstr_fd(value, 1);
			}
			if (str[i] == 'x' || str[i] == 'X')
			{
				res += intToHex(va_arg(args, unsigned int), str[i]);
			}
			if (str[i] == 'p')
			{
				res += ft_putstr_fd("0x", 1);
				res += intToHex(va_arg(args, unsigned long), str[i]);
			}
			if (str[i] == '%')
			{
				res += ft_putchar_fd('%', 1);
			}
		}
		else
		{
			res += ft_putchar_fd(str[i], 1);
		}
		i++;
	}
	va_end(args);
	return (res);
}

// int	main()
// {
	
// 	unsigned long y = ULLONG_MAX;
// 	int res = 0;
// 	int k = 0;
// // // // 	print_number("--------ft_printf--------: \n");
// // // // 	res = print_number("%d", -1235);
// // // // 	print_number("\nlen: %d\n", res);
// // // // 	print_number("------------------------\n");
// // // // 	res = 0;
// // // // 	res = print_number("%c\n", 'c');
// // // // 	print_number("len: %d\n", res);
// // // // 	print_number("------------------------\n");
// // // // 	res = 0;
// // // // 	res = print_number("%s\n", NULL);
// // // // 	print_number("len: %d\n", res);
// // // // 	print_number("------------------------\n");
// // // // 	res = 0;
// // // // 	res = print_number("%X\n", 123456789);
// // // // 	print_number("len: %d\n", res);
// // 	ft_printf("------------------------\n");
// // 	res = 0;
// // 	res = ft_printf("0x%p-", (void *)ULONG_MAX);
// // 	ft_printf("\nlen: %d\n", res);
// // 	ft_printf("------------------------\n");
// // // 	res = 0;
// // // 	ft_printf("%%%c", 'x');
// // // 	ft_printf("\nlen: %d\n", res);
// // // // 	printf("--------printf----------: \n");
// // // // 	res = 0;
// // // // 	res = printf("%d", -1235);
// // // // 	printf("\nlen: %d\n", res);
// // // // 	printf("------------------------\n");
// // // // 	res = 0;
// // // // 	res = printf("%c\n", 'c');
// // // // 	printf("len: %d\n", res);
// // // // 	printf("------------------------\n");
// // // // 	res = 0;
// // // // 	res = printf("%s\n", NULL);
// // // // 	printf("len: %d\n", res);
// // // // 	printf("------------------------\n");
// // // // 	res = 0;
// // // // 	res = printf("%X\n", 123456789);
// // // // 	printf("len: %d\n", res);
// // 	printf("------------------------\n");
// // 	res = 0;
// // 	res = printf("0x%p-", (void *)ULONG_MAX);
// // 	printf("\nlen: %d\n", res);
// // 	printf("------------------------\n");
// // // 	res = 0;
// // // 	printf("%%%c", 'x');
// // // 	printf("\nlen: %d\n", res);
// // // // 	// print_number("%d, %d, %c, %d, %s, 0x%X \n", -125, -123, 'a', 121, NULL, y);
// // // // 	// printf("%d, %d, %c, %d, %s, 0x%lX \n", -125, -123, 'a', 121, NULL, y);
// res = 0;
// res = ft_printf("\001\002\007\v\010\f\r\n");
// ft_printf("%d\n", res);
// res = ft_printf("*************************");
// res = 0;
// printf("\001\002\007\v\010\f\r\n");
// printf("%d\n", res);
// }
