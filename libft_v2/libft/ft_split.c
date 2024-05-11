/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lganda <lgandari@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:48:33 by lganda            #+#    #+#             */
/*   Updated: 2024/02/28 17:20:55 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_countparts(char const *s, char c)
{
	int	i;
	int	parts;

	i = 0;
	parts = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c))
			parts++;
		i++;
	}
	return (parts);
}

void	ft_freesplit(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
}

size_t	calcpartsize(char const *s, char c)
{
	size_t	partsize;

	partsize = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		partsize++;
	}
	return (partsize);
}

int	ft_allocatepart(char **aux, size_t partsize, size_t i)
{
	aux[i] = (char *)malloc(sizeof(char) * (partsize + 1));
	if (!aux[i])
	{
		ft_freesplit(aux);
		free(aux);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**aux;
	size_t	parts;
	size_t	partsize;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	parts = ft_countparts(s, c);
	aux = (char **)malloc(sizeof(char *) * (parts + 1));
	if (!aux)
		return (NULL);
	while (i != parts && *s)
	{
		while (*s == c)
			s++;
		partsize = calcpartsize(s, c);
		if (ft_allocatepart(aux, partsize, i) != 0)
			return (NULL);
		ft_strlcpy(aux[i++], s, partsize + 1);
		s += partsize;
	}
	aux[i] = NULL;
	return (aux);
}
