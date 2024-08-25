/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:38:44 by mrao              #+#    #+#             */
/*   Updated: 2024/08/25 18:23:58 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_hex(unsigned long hxd, char symbol)
{
	char	*base;
	int		i;
	int		temp_xd;
	char	digit;

	i = 0;
	if (symbol == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (hxd > 16)
	{
		temp_xd = printf_hex(hxd / 16, symbol);
		if (temp_xd == -1)
			return (-1);
		i += temp_xd;
	}
	digit = base[hxd % 16];
	if (write(1, &digit, 1) == -1)
		return (-1);
	i += 1;
	return (i);
}
