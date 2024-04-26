/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:24:15 by ohaida            #+#    #+#             */
/*   Updated: 2024/04/26 21:29:37 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 1;
	while (*s)
	{
		if (*s == c)
			in_word = 1;
		else
		{
			if (in_word)
			{
				in_word = 0;
				count++;
			}
		}
		s++;
	}
	return (count);
}

static char	*ft_strdub(char const *s, int len)
{
	char	*result;
	int		i;

	result = (char *)ft_malloc(len + 1, 0);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static void	fill(char **result, char const *s, char c, int word_count)
{
	int	i;
	int	len;

	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		result[i] = ft_strdub(s, len);
		s += len;
		i++;
	}
}

char	**ft_split(char *s, char c)
{
	int		word_count;
	char	**result;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)ft_malloc(sizeof(char *) * (word_count + 1), 0);
	if (!result)
		return (NULL);
	fill(result, s, c, word_count);
	result[word_count] = NULL;
	while (i < word_count)
	{
		if (!result[i])
			return (NULL);
		i++;
	}
	return (result);
}
