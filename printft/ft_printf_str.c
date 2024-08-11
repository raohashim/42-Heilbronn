/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:40:11 by mrao              #+#    #+#             */
/*   Updated: 2024/08/11 15:16:28 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i += 6;
		write(1, "(null)", 6);
		return (i);
	}
	while (str[i])
	{
		printf_char((int)str[i]);
		i++;
	}
	return (i);
}
