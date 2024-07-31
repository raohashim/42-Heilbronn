/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 07:26:55 by mrao              #+#    #+#             */
/*   Updated: 2024/07/14 15:23:27 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// It is used to return  a pointer to a null-terminated byte string,
// The strdup() and strndup() functions are used to duplicate a string. 
char	*ft_strdup(const char	*str)
{
	char	*dup_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	dup_str = (char *)malloc((i + 1) * sizeof(char));
	if (!dup_str)
		return (NULL);
	if (dup_str != NULL)
	{
		while (str[j] != '\0')
		{
			dup_str[j] = str[j];
			j++;
		}
	}
	dup_str[j] = '\0';
	return (dup_str);
}
