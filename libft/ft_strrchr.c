/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 08:31:04 by mrao              #+#    #+#             */
/*   Updated: 2024/07/05 06:21:07 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*str, int ch)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
		j++;
	while (j > -1)
	{
		if (str[j] == (char)ch)
			return ((char *)str + j);
		j--;
	}
	return (NULL);
}
