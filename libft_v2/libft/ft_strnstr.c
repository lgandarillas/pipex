/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:26:39 by lgandari          #+#    #+#             */
/*   Updated: 2024/02/28 17:22:39 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*ptr;

	if (*little == '\0')
		return ((char *)big);
	if (*big == '\0')
		return (0);
	i = 0;
	ptr = (char *)big;
	n_len = ft_strlen(little);
	if (n_len == 0 || big == little)
		return ((char *)big);
	while (ptr[i] != '\0' && i < len)
	{
		j = 0;
		while (ptr[i + j] != '\0' && little[j] != '\0'
			&& ptr[i + j] == little[j] && i + j < len)
			j++;
		if (j == n_len)
			return (ptr + i);
		i++;
	}
	return (0);
}
