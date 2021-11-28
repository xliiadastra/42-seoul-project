/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:33:19 by yichoi            #+#    #+#             */
/*   Updated: 2021/11/23 14:25:29 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*ptr;

	ptr = (unsigned char	*)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
			return ((char	*)ptr);
		ptr++;
	}
	if ((unsigned char)c == '\0')
		return ((char	*)ptr);
	else
		return (NULL);
}
