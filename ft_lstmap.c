/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:03:02 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/06 19:31:19 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*ptr;

	if (!lst)
		return (NULL);
	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->next = (NULL);
	ptr = head;
	while (lst)
	{
		(*f)(lst->content);
		head = ft_lstnew(lst->content);
		lst = lst->next;
		head = head->next;
	}
	head = ptr;
	(*del)(ptr->content);
	free(ptr);
	return (head);
}
