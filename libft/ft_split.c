// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_split.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/11/04 14:24:15 by ohaida            #+#    #+#             */
// /*   Updated: 2023/11/05 11:18:26 by ohaida           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "libft.h"

// #include <stdio.h>

// static void	free_arr(char **str, int k)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= k)
// 	{
// 		free(str[i]);
// 	}
// 	free(str);
// }

// static char	*ft_sub(const char *s1, unsigned int i, size_t len)
// {
// 	char	*str;
// 	int		j;

// 	j = 0;
// 	str = malloc(len - i + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	while (s1[j] && i < len)
// 	{
// 		str[j] = s1[i];
// 		i++;
// 		j++;
// 	}
// 	str[j] = '\0';
// 	return (str);
// }

// static size_t	num_len(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		while (s[i] && s[i + 1] == c)
// 			i++;
// 		if (s[i] == c)
// 			j++;
// 		i++;
// 	}
// 	if (s[i - 1] != c)
// 		j++;
// 	return (j);
// }

// static char	**fill(char **str, char *s, char c)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	k;

// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	while (1)
// 	{
// 		while (s[i] && s[i] == c)
// 			i++;
// 		j = i;
// 		while (s[j] && s[j] != c)
// 			j++;
// 		str[k] = ft_sub(s, i, j);
// 		if (str[k] == NULL)
// 		{
// 			free_arr(str, k);
// 			return (NULL);
// 		}
// 		k++;
// 		i = j + 1;
// 		if (!s[j] || !s[i])
// 			break ;
// 	}
// 	str[k] = NULL;
// 	return (str);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**str;
// 	char	*x;

// 	x = ft_strtrim(s, &c);
// 	str = malloc((num_len(x, c) + 1) * sizeof(char *));
// 	if (str == NULL)
// 		return (NULL);
// 	str = fill(str, x, c);
// 	return (str);
// }

// // int main()
// // {
// // 	char **s;

// // 	s = ft_split("\0aa\0bbb", '\0');
// // 	while (*s){
// // 		printf("%s\n", *s);
// // 		s++;
// // 	}
// // }