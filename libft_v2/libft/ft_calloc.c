/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:50:25 by lgandari          #+#    #+#             */
/*   Updated: 2024/03/08 19:47:07 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*buffer;
	size_t	i;

	i = 0;
	buffer = (char *)malloc(size * nmemb);
	if (!buffer)
		return (NULL);
	while (i < nmemb * size)
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}
