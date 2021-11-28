/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:28:14 by yichoi            #+#    #+#             */
/*   Updated: 2021/11/27 21:58:58 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_word(char const *s, int c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while ((s[i] != c) && s[i])
				i++;
		}
		i++;
	}
	return (count);
}

static size_t	ft_find(char const *s, int c, size_t start)
{
	while (s[start])
	{
		if (s[start] == c)
			return (start - 1);
		start++;
	}
	return (start - 1);
}

static int	ft_free(char **s, size_t index)
{
	if (!s[index])
	{
		free(s);
		return (0);
	}
	else
		return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	word_count;
	size_t	i;
	size_t	j;
	size_t	z;

	i = 0;
	z = 0;
	word_count = is_word(s, c);
	ptr = (char **)malloc(sizeof(char *) * word_count + 1);
	if (!ptr)
		return (NULL);
	while (s[i] && (s[i] == c))
		i++;
	while (word_count--)
	{
		j = ft_find(s, c, i);
		ptr[z] = ft_substr(ptr[z], s[i], s[j] - s[i] + 1);
		if (!ft_free(ptr, z))
			return (NULL);
		z++;
		i = j + 1;
	}
	ptr[z] = '\0';
	return (ptr);
}
