/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:17:53 by ohaida            #+#    #+#             */
/*   Updated: 2024/04/01 17:56:49 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/minitalk.h"

void	ft_send(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "Error PID!\n", 12);
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "Error PID!\n", 12);
				exit(0);
			}
		}
		c >>= 1;
		usleep(860);
		i++;
	}
}

void	ft_send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send(pid, str[i]);
		i++;
	}
	ft_send(pid, '\0');
}

int	checkdigit(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] < '0' || c[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(2, "Usage: ./client <PID> <MESSAGE>\n", 33);
		return (0);
	}
	if (checkdigit(argv[1]) == 1)
	{
		write(2, "Invalid PID!\n", 11);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "Wrong PID!\n", 11);
		return (0);
	}
	ft_send_str(pid, argv[2]);
	return (0);
}
