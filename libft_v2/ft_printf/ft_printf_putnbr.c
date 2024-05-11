/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lganda <lgandari@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:19:23 by lganda            #+#    #+#             */
/*   Updated: 2024/02/28 17:13:21 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putnbr(int n)
{
	int				len;
	unsigned int	aux;
	unsigned int	nbr;

	len = 0;
	aux = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		nbr = n * -1;
	}
	else
		nbr = n;
	if (nbr > 9)
		len += ft_putnbr(nbr / 10);
	aux = (nbr % 10);
	len += ft_putchar(aux + '0');
	return (len);
}

int	ft_putnbr_uns(unsigned int n)
{
	int	len;
	int	aux;

	len = 0;
	if (n >= 10)
		len += ft_putnbr_uns(n / 10);
	aux = (n % 10);
	len += ft_putchar(aux + '0');
	return (len);
}

int	ft_putnbr_hex(unsigned int n, char format)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_putnbr_hex(n / 16, format);
		len += ft_putnbr_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			len += ft_putchar(n + '0');
		else
		{
			if (format == 'x')
				len += ft_putchar(n - 10 + 'a');
			else if (format == 'X')
				len += ft_putchar(n - 10 + 'A');
		}
	}
	return (len);
}
