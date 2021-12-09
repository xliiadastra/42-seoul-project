/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:41:58 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/09 18:06:24 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	valid(int n, int fd)
{
	char	*min_int;

	if (fd < 0)
		return (0);
	min_int = "-2147483648";
	if (n == -2147483648)
	{
		write(fd, min_int, 11);
		return (0);
	}
	return (1);
}

static char	*itoa_fd(int n, int *len)
{
	char	*ptr[11];
	int		i;
	int		n_len;

	i = 0;
	n_len = *len;
	while (i < 11)
		ptr[i++] = 0;
	while (n)
	{
		ptr[n_len] = n % 10 + '0';
		n /= 10;
		n_len--;
	}
	*len = n_len;
	return (ptr);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	*ptr;
	int		len;

	if (!valid(n, fd))
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	len = 9;
	ptr = itoa_fd(n, &len);
	while (++len <= 9)
		write(fd, &ptr[len], 1);
}
