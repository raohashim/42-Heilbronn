/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:20:53 by mrao              #+#    #+#             */
/*   Updated: 2024/07/14 15:24:18 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (!*little)
		return ((char *)big);
	little_len = 0;
	while (little[little_len])
		little_len++;
	while (*big && len-- >= little_len)
	{
		if (*big == *little && !ft_strncmp(big, little, little_len))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
