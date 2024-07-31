/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:03:08 by mrao              #+#    #+#             */
/*   Updated: 2024/07/11 03:49:53 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*ft_strndup(const char *src, int n)
{
	char	*dst;
	int		i;

	dst = (char *)malloc((n + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*next_word(const char **s, char c)
{
	const char	*start;
	int			len;

	while (**s == c && **s)
		(*s)++;
	start = *s;
	len = 0;
	while ((*s)[len] != c && (*s)[len])
		len++;
	*s += len;
	return (ft_strndup(start, len));
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		total_words;
	int		i;

	total_words = count_words(s, c);
	split = (char **)malloc((total_words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (i < total_words)
	{
		split[i] = next_word(&s, c);
		if (!split[i])
			return (free_split(split, i), NULL);
		i++;
	}
	split[total_words] = NULL;
	return (split);
}
