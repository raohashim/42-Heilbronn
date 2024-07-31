/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 08:14:40 by mrao              #+#    #+#             */
/*   Updated: 2024/07/14 15:24:36 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s_str;
	unsigned int	j;
	unsigned int	s_ind;

	j = 0;
	s_ind = 0;
	if (!s)
		return (NULL);
	s_ind = ft_strlen(s);
	if (start >= s_ind)
		return (ft_strdup(""));
	if (len > s_ind - start)
		len = s_ind - start;
	s_str = (char *)malloc(len + 1);
	if (!s_str)
		return (NULL);
	while (s[start] != '\0' && (len) != 0)
	{
		s_str[j] = s[start];
		j++;
		start++;
		len--;
	}
	s_str[j] = '\0';
	return (s_str);
}
