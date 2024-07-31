/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 07:48:40 by mrao              #+#    #+#             */
/*   Updated: 2024/07/14 15:19:46 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// numElements: The number of elements you want to allocate memory for.
// sizeOfElement: The size of each element in bytes.
void	*ft_calloc(size_t	num_of_elements, size_t	size_of_elements)
{
	void	*ptr;
	char	*charptr;
	size_t	i;

	i = 0;
	ptr = malloc(num_of_elements * size_of_elements);
	if (ptr != NULL)
	{
		charptr = (char *)ptr;
		while (i < (num_of_elements * size_of_elements))
		{
			charptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}
