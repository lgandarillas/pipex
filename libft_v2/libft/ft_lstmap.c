/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lganda <lgandari@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:53:14 by lganda            #+#    #+#             */
/*   Updated: 2024/02/28 17:17:03 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_newnode(void *content)
{
	t_list	*new;

	new = malloc (sizeof(t_list));
	if (!new)
	{
		free(content);
		return (NULL);
	}
	new -> content = content;
	new -> next = NULL;
	return (new);
}

void	ft_freelst(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*next;

	aux = *lst;
	while (aux != NULL)
	{
		next = aux -> next;
		del(aux -> content);
		free(aux);
		aux = next;
	}
	*lst = NULL;
}

void	ft_addback_lstmap(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	aux = *lst;
	while (aux -> next)
		aux = aux -> next;
	aux -> next = new;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = NULL;
	while (lst)
	{
		aux = ft_newnode(f(lst -> content));
		if (aux == NULL)
		{
			ft_freelst(&new, del);
			return (NULL);
		}
		ft_addback_lstmap(&new, aux);
		lst = lst -> next;
	}
	return (new);
}
