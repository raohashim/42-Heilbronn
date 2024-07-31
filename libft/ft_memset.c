/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:31:56 by mrao              #+#    #+#             */
/*   Updated: 2024/07/14 15:08:27 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	void	*ptr_start;

	ptr_start = ptr;
	while (num > 0)
	{
		*(char *)ptr = value;
		ptr++;
		num--;
	}
	return (ptr_start);
}
