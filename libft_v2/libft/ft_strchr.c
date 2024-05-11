/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:55:31 by lgandari          #+#    #+#             */
/*   Updated: 2024/03/08 19:45:58 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c < 0 || c > 255)
		c = (unsigned int)c % 256;
	while (*s != '\0' && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	else
		return (NULL);
}
