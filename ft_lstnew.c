/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:51:14 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/05 20:22:50 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	void	*ptr;

	ptr = (void *)malloc(sizeof(content));
	t_list->content = ptr;
	if (t_list->next)
		t_list->next = NULL;
	return (t_list);
}
