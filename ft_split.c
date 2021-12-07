/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:28:14 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/07 21:26:17 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

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

static int	is_char(char s, char c)
{
	if (s == c)
		return (1);
	else
		return (0);
}

static void	ft_free(char **ptr, size_t count)
{
	while (count >= 0)
		free(ptr[count--]);
	free(ptr);
	ptr = NULL;
}

static char	*split_strdup(char const *s, size_t *start, char c)
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
		return (NULL);
	while (len--)
	{
		ptr[i] = s[*start + i];
		i++;
	}
	*start = end;
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	word_count;
	size_t	index;
	size_t	i;

	index = 0;
	if (!s)
		return (NULL);
	word_count = is_word(s, c);
	ptr = (char **)malloc(sizeof(char *) * word_count + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	index = 0;
	while (s[i])
	{
		if (!is_char(s[i], c))
		{
			ptr[index] = split_strdup(s, &i, c);
			if (!ptr[index])
			{
				ft_free(ptr, index);
				return (NULL);
			}
			index++;
		}
		else
			i++;
	}
	ptr[index] = NULL;
	return (ptr);
}

//int main()
//{
//	char s1[] = {"hello  fucking     apple  !  "};
//	char c = ' ';
//	char	**ptr;
//
//	ptr = ft_split(s1, c);
//	for (int i = 0; i < 4; i++)
//		printf("%s\n", ptr[i]);
//}
