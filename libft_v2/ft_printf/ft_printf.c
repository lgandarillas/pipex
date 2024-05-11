/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lganda <lgandari@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:58:56 by lganda            #+#    #+#             */
/*   Updated: 2024/02/28 17:13:01 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_format(char *format, va_list arg)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (*format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (*format == 'p')
		return (ft_putptr(va_arg(arg, unsigned long long)));
	if (*format == 'd' || *format == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (*format == 'u')
		return (ft_putnbr_uns(va_arg(arg, unsigned int)));
	if (*format == 'x' || *format == 'X')
		return (ft_putnbr_hex(va_arg(arg, unsigned int), *format));
	if (*format == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		aux;
	va_list	arg;

	if (!str)
		return (-1);
	len = 0;
	va_start(arg, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			aux = ft_format((char *)str, arg);
			if (aux == -1)
				return (-1);
			len += aux;
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(arg);
	return (len);
}
