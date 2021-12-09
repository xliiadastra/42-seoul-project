/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:28:14 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/09 20:04:55 by yichoi           ###   ########.fr       */
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

void	ft_free(char **ptr)
{
	size_t	index;

	index = 0;
	while (ptr[index])
	{
		free(ptr[index]);
		index++;
	}
	free(ptr);
	ptr = NULL;
}

static char	*split_strdup(char const *s, size_t *start, char c, char **s_ptr)
{
	char	*ptr;
	size_t	i;
	size_t	end;
	size_t	len;

	i = 0;
	end = *start;
	while (s[end] && s[end] != c)
		end++;
	len = end - *start;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
	{
		ft_free(s_ptr);
		return (NULL);
	}
	while (len--)
	{
		ptr[i] = s[*start + i];
		i++;
	}
	*start = end;
	ptr[i] = '\0';
	return (ptr);
}

static int	valid(char const *s, char **ptr)
{
	if (!s || !ptr)
	{
		free(ptr);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	word_count;
	size_t	index;
	size_t	i;

	if (!s)
		return (NULL);
	word_count = is_word(s, c);
	ptr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!valid(s, ptr))
		return (NULL);
	ptr[word_count] = NULL;
	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			ptr[index] = split_strdup(s, &i, c, ptr);
			if (!ptr[index])
				return (NULL);
			index++;
		}
		else
			i++;
	}
	return (ptr);
}
