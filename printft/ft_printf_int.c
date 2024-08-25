/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 07:19:22 by mrao              #+#    #+#             */
/*   Updated: 2024/08/25 18:22:50 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_int(long d)
{
	int		i;
	int		temp_d;
	char	digit;

	i = 0;
	if (d < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		i++;
		d = d * -1;
	}
	if (d > 9)
	{
		temp_d = printf_int(d / 10);
		if (temp_d == -1)
			return (-1);
		i += temp_d;
	}
	digit = (d % 10) + '0';
	if (write(1, &digit, 1) == -1)
		return (-1);
	i++;
	return (i);
}
