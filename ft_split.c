/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:28:14 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/03 21:43:19 by yichoi           ###   ########.fr       */
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
		else
			i++;
	}
	return (count);
}

static int	ft_find(char s, char c)
{
	if (s == c)
		return (1);
	else
		return (0);
}

static int	ft_free(char **s, size_t count)
{
	while (count--)
	{
		if (!s[count])
		{
			free(s);
			return (0);
		}
	}
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
	j = 0;
	z = 0;
	if (!s)
		return (NULL);
	word_count = is_word(s, c);
	ptr = (char **)malloc(sizeof(char *) * word_count + 1);
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		if (!ft_find(s[i], c))
		{
			j = i;
			while (s[j] != c && s[j])
				j++;
			if (j != i)
				ptr[z] = ft_substr(s, (unsigned int)i, j - i + 1);
			else
				break ;
			i = j;
			z++;
		}
		else
			i++;
	}
	if (!ft_free(ptr, word_count))
		return (NULL);
	return (ptr);
}
