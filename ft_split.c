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

int	is_word(char const *s, int c, int count)
{
	size_t	i;

	i = 0;
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

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int	word_count;
	size_t	i;

	i = 0;
	word_count = is_word(s, c, word_count);
	ptr = (char *)malloc(sizeof(char) * word_count + 1);
	if (!ptr)
		return (NULL);
}
