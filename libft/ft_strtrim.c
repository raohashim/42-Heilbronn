/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 08:47:40 by mrao              #+#    #+#             */
/*   Updated: 2024/07/14 15:24:29 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trm_str;
	size_t	start_cnt;
	size_t	end_cnt;
	size_t	len;

	start_cnt = 0;
	end_cnt = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start_cnt] && ft_strchr(set, s1[start_cnt]))
		start_cnt++;
	while (end_cnt > start_cnt && ft_strchr(set, s1[end_cnt - 1]))
		end_cnt--;
	len = end_cnt - start_cnt +1;
	trm_str = malloc(len);
	if (!trm_str)
		return (NULL);
	ft_strlcpy(trm_str, &s1[start_cnt], len);
	return (trm_str);
}
