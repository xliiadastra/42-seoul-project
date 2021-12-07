/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:13:55 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/07 21:18:19 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_nu(int n)
{
	size_t	count;

	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	negative(char	*ptr, int n, int sign, size_t count)
{
	if (sign < 0)
	{
		ptr[0] = '-';
		ptr[count + 2] = '\0';
		while (n && (count > 0))
		{
			ptr[count--] = (n % 10) + '0';
			n = n / 10;
		}
	}
	else
	{
		ptr[count] = '\0';
		while (n && --count >= 0)
		{
			ptr[count] = (n % 10) + '0';
			n = n / 10;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	count;

	count = count_nu(n);
	if (n < 0)
		ptr = (char *)ft_calloc(count + 2, sizeof(char));
	else
		ptr = (char *)ft_calloc(count + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		negative(ptr, -(n / 10), -1, count);
		ptr[count + 1] = -(n % 10);
	}
	else
		negative(ptr, n, 1, count);
	return (ptr);
}
