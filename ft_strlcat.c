/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:33:11 by yichoi            #+#    #+#             */
/*   Updated: 2021/11/16 17:10:39 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * SYNOPSIS		 : <string.h>
 * DESCRIPTION 	 : strlcat() appends string src to the end of dst.  It will append at most dstsize - strlen(dst) - 1 characters. It will
     then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize (in practice this should not
     happen as it means that either dstsize is incorrect or that dst is not a proper string).
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while (src[i] && dst_len + i + 1 < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
