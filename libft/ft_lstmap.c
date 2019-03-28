/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:12:12 by sbruen            #+#    #+#             */
/*   Updated: 2018/12/14 13:56:29 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*new_list;

	if (!lst)
		return (NULL);
	new_list = f(lst);
	list = new_list;
	while (lst->next)
	{
		lst = lst->next;
		new_list->next = f(lst);
		if (!new_list->next)
			return (NULL);
		new_list = new_list->next;
	}
	return (list);
}
