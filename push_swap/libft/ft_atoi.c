/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:21:40 by ohaida            #+#    #+#             */
/*   Updated: 2024/04/05 01:21:03 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

static int	is_space(char c)
{
	if (c == '\f' || c == '\n' || c == ' ')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static const char	*is_oper(char c, const char **str, int *neg)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			*neg = (*neg) * -1;
		return ((*str) + 1);
	}
	return (*str);
}

int	check_overflow(long long n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (1);
	return (0);
}

int	check_max_long(unsigned long long n, int neg)
{
	if (n >= ~((unsigned long long)1 << 63) && neg == 1)
		return (-1);
	if (n >= ((unsigned long long)1 << 63) && neg == -1)
		return (0);
	return (1);
}

long long	ft_atoi(const char *str)
{
	unsigned long long n;
	int	neg;

	n = 0;
	neg = 1;
	while (is_space(*str))
		str++;
	str = is_oper(*str, &str, &neg);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (n * neg);
		if (check_overflow(n) || (n != n * neg))
		{
			ft_printf("Error: Overflow detected.\n");
			exit(1);
		}
		n = n * 10 + (*str) - '0';
		str++;
	}
	if (check_max_long(n, neg) <= 0)
		return (check_max_long(n, neg));
	return (n * neg);
}
