/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:35:38 by mrao              #+#    #+#             */
/*   Updated: 2024/07/31 17:36:54 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
