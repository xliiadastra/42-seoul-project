/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:36:45 by yichoi            #+#    #+#             */
/*   Updated: 2021/11/27 20:45:28 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
//	size_t	size;

	i = 0;
//	size = ft_strlen(s);
	if (!s)
		return (NULL);
//	if (size <= start)
//	{
//		ptr = malloc(1);
//		if (!ptr)
//			return (NULL);
//		*ptr = '\0';
//		return (ptr);
//	}
//	else
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	while (s[start] && i < len)
	{
		ptr[i] = s[(size_t)start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
