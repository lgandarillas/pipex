/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:40:23 by lgandari          #+#    #+#             */
/*   Updated: 2024/02/28 17:23:04 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*snew;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	end = ft_strlen(&s1[start]);
	if (end != 0)
		while (s1[start + end - 1]
			&& ft_strchr(set, s1[start + end - 1]))
			end--;
	snew = (char *)malloc(sizeof(char) * (end + 1));
	if (!snew)
		return (NULL);
	ft_memcpy(snew, &s1[start], end);
	snew[end] = '\0';
	return (snew);
}
