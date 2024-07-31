/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 05:56:08 by mrao              #+#    #+#             */
/*   Updated: 2024/07/11 03:18:01 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n_bytes)
{
	while (n_bytes > 0)
	{
		if (*(char *)s == (char) c)
		{
			return ((void *)s);
		}
		n_bytes--;
		s++;
	}
	return (NULL);
}
