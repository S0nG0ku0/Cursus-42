/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:13:13 by ohaida            #+#    #+#             */
/*   Updated: 2024/05/12 22:42:56 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int nb, int fd);
int	ft_putchar_fd(char c, int fd);
int	intohex(unsigned long number, char c);
int	ft_putnbr_fd_u(unsigned int nb, int fd);

#endif