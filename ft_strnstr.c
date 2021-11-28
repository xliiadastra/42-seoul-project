/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:20:47 by yichoi            #+#    #+#             */
/*   Updated: 2021/11/27 17:11:22 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*ptr;
	size_t	i;

	i = 0;
	if (!needle)
		return ((char	*)haystack);
	while (haystack[i] && i < len)
	{
		ptr = needle;
		if (haystack[i] == *ptr)
		{
			size_t	j;

			j = i;
			while (haystack[j] == *ptr)
			{
				ptr++;
				j++;
			}
			if (*ptr == '\0')
				return ((char	*)haystack + i);
		}
		i++;
	}
	return (NULL);
}
