/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lganda <lgandari@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:09:06 by lganda            #+#    #+#             */
/*   Updated: 2023/10/10 12:40:22 by lganda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_format(char	*format, va_list arg);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbr_uns(unsigned int n);
int	ft_putptr(unsigned long long n);
int	ft_putptr_hex(unsigned long long n);
int	ft_putnbr_hex(unsigned int n, char c);

#endif
