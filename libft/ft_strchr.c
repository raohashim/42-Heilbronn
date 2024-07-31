/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 08:31:04 by mrao              #+#    #+#             */
/*   Updated: 2024/07/14 15:23:17 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strchr function in C is used to search for the 
// first occurrence of a specified character in a given string. 
char	*ft_strchr(const char	*str, int ch)
{
	while (*str != '\0')
	{
		if ((unsigned char)*str == (unsigned char)ch)
		{
			return ((char *) str);
		}
		str++;
	}
	if ((unsigned char)ch == '\0')
		return ((char *)str);
	return (NULL);
}
