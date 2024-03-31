/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:17:46 by ohaida            #+#    #+#             */
/*   Updated: 2024/03/30 20:52:46 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/minitalk.h"

void	ft_print(int sig, siginfo_t *info, void *contx)
{
	static int	i;
	static char	c;
	static int	old;

	(void)contx;
	if (old != info->si_pid)
	{
		old = info->si_pid;
		i = 0;
		c = 0;
	}
	if (sig == SIGUSR1)
		c += 1 << i;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	act;

	write(1, "PID : ", 6);
	ft_putnbr_fd(getpid(), 1);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_print;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
