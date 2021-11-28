/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 20:22:01 by yichoi            #+#    #+#             */
/*   Updated: 2021/11/27 17:12:48 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end]))
		end--;
	if (end <= 0)
		return (ft_strdup(""));
	ptr = (char	*)malloc(sizeof(char) * (end - start + 1));
	if (!ptr)
		return (NULL);
	return (NULL);
}
