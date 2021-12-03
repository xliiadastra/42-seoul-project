#include "libft.h"
#include <stdio.h>

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

static void	negative(char	*ptr, int n, size_t count)
{
	if (n < 0)
	{
		ptr[0] = '-';
		ptr[count + 1] = '\0';
		while (n && (--count > 1))
		{
			ptr[count] = (n % 10) + '0';
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
		negative(ptr, -(n / 10), count);
		ptr[1] = -(n % 10);
	}
	else
		negative(ptr, n, count);
	return (ptr);
}
