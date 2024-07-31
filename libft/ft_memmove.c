/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:43:52 by mrao              #+#    #+#             */
/*   Updated: 2024/07/14 15:14:56 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// It is different from the memcoy as it first copy the data from 
// source object to a
// temporary array and then move from temporary arry to destination array.
// It allows to copy between objects that can overlap.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*dst_start;

	dst_start = dst;
	if (!dst_start && !src)
		return (dst_start);
	if (dst > src)
	{
		dst += len;
		src += len;
		while (len > 0)
		{
			*(char *)--dst = *(char *)--src;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*(char *)dst++ = *(char *)src++;
			len--;
		}
	}
	return (dst_start);
}
