/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:09:26 by lgandari          #+#    #+#             */
/*   Updated: 2024/03/08 19:40:44 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && *s)
	{
		len++;
		s++;
	}
	return (len);
}
