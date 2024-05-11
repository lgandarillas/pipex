/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:00:03 by lgandari          #+#    #+#             */
/*   Updated: 2024/02/28 17:15:52 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_countdigits(int n)
{
	int			digits;
	long int	num;

	num = n;
	digits = 0;
	if (n < 0)
	{
		digits++;
		num *= -1;
	}
	while (num > 9)
	{
		num /= 10;
		digits++;
	}
	digits++;
	return (digits);
}

char	*ft_itoa(int n)
{
	int			idx;
	char		*result;
	const char	*digits = "0123456789";

	idx = ft_countdigits(n);
	result = malloc(sizeof(char) * (idx + 1));
	if (!result)
		return (0);
	result[idx] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	while (n)
	{
		if (n > 0)
			result[--idx] = digits[n % 10];
		else
			result[--idx] = digits[n % 10 * (-1)];
		n /= 10;
	}
	return (result);
}
