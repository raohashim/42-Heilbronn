/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:57:24 by mrao              #+#    #+#             */
/*   Updated: 2024/08/25 18:28:51 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex_digit(unsigned long long num, int *len)
{
	if (num <= 9)
		printf_char(num + '0');
	else
		printf_char(num - 10 + 'a');
	(*len)++;
}

void	ft_put_ptr_rec(unsigned long long num, int *len)
{
	if (num >= 16)
	{
		ft_put_ptr_rec(num / 16, len);
		ft_put_ptr_rec(num % 16, len);
	}
	else
		ft_put_hex_digit(num, len);
}

int	printf_ptr(void *ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len += printf_str("0x0");
	else
	{
		if (printf_str("0x") == -1)
			return (-1);
		len += 2;
		ft_put_ptr_rec((unsigned long long)ptr, &len);
	}
	return (len);
}
