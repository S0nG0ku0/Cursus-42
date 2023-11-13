/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:34:00 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/13 18:22:08 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void intToHex(unsigned int number, char c)
{
	int x;
	int remainder;
	
    if (number == 0)
    {
        return;
    }
    remainder = number % 16;
    intToHex(number / 16, c);
    if (remainder < 10)
    		x = remainder + '0';
    else
	{
		if (c == 'x')
			x = remainder + 'a' - 10;
		if (c == 'X')
			x = remainder + 'A' - 10;
	}
	ft_putchar_fd(x, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	ft_putchar_fd('0' + nb % 10, fd);
}

void	print_number(char *str, ...)
{
	va_list	args;
	int		i;
	char	*value;
	int		intValue;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'd')
			{
				intValue = va_arg(args, int);
				ft_putnbr_fd(intValue, 1);
			}
			if (str[i] == 'c')
			{
				intValue = va_arg(args, int);
				ft_putchar_fd(intValue, 1);
			}
			if (str[i] == 's')
			{
				value = va_arg(args, char *);
				ft_putstr_fd(value, 1);
			}
			if (str[i] == 'x' || str[i] == 'X')
			{
				intToHex(va_arg(args, int), str[i]);
			}
		}
		else
		{
			ft_putchar_fd(str[i], 1);
		}
		i++;
	}
	va_end(args);
}

int	main()
{
	print_number("%d, %d, %c, %d, %s, 0x%X \n", 125, 123, 'h', 121, "omar", -1);
}
