/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:13:13 by ohaida            #+#    #+#             */
/*   Updated: 2023/11/19 20:33:51 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int nb, int fd);
int	ft_putchar_fd(char c, int fd);
int	intohex(unsigned long number, char c);
int	ft_putnbr_fd_u(unsigned int nb, int fd);

#endif