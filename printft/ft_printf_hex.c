/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:38:44 by mrao              #+#    #+#             */
/*   Updated: 2024/08/08 17:02:48 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_hex(unsigned int hxd, char symbol)
{
	char	*hex_digits;
	int		len;

	len = 0;
	if (symbol == 'x')
		hex_digits = "0123456789abcdef";
	else if (symbol == 'X')
		hex_digits = "0123456789ABCDEF";
	if (hxd < 16)
		return (printf_char(hex_digits[hxd]));
	else
	{
		len = printf_hex(hxd / 16, symbol);
		return (len + printf_hex(hxd % 16, symbol));
	}
}
