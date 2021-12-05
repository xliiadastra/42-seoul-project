/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:41:58 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/05 20:07:39 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*ptr;
	size_t	len;

	ptr = ft_itoa(n);
	if (!ptr)
		return ;
	len = ft_strlen(ptr);
	write(fd, ptr, len);
}
