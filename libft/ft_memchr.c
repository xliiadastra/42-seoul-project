/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:09:01 by yichoi            #+#    #+#             */
/*   Updated: 2021/11/27 18:14:42 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t	i;

	i = 0;
	ptr = s;
	while (ptr[i] && i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void	*)&ptr[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((void	*)&ptr[i]);
	else
		return (NULL);
}
