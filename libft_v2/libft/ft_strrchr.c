/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:12:00 by lgandari          #+#    #+#             */
/*   Updated: 2024/02/28 17:22:55 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	pos;

	c = c % 256;
	pos = ft_strlen(s);
	while (pos >= 0)
	{
		if (s[pos] == c)
			return ((char *)&s[pos]);
		pos--;
	}
	return (0);
}
