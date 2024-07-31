/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:00:19 by mrao              #+#    #+#             */
/*   Updated: 2024/07/14 15:20:47 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memcmp() function returns  an  integer  less  than,  equal  to,  or
// greater than zero if the first n bytes of s1 is found, respectively, to
// be less than, to match, or be greater than the first n bytes of s2.
int	ft_memcmp(const void *str1, const void *str2, size_t n_bytes)
{
	while (n_bytes > 0)
	{
		if (*(unsigned char *)str1 != *(unsigned char *)str2)
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		str1++;
		str2++;
		n_bytes--;
	}
	return (0);
}
