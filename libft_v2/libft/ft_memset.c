/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:34:56 by lgandari          #+#    #+#             */
/*   Updated: 2024/02/28 17:19:13 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*copyb;

	i = 0;
	copyb = b;
	while (i < n)
	{
		copyb[i] = (unsigned char)c;
		i++;
	}
	return (copyb);
}
