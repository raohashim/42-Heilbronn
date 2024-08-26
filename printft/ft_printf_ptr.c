/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:57:24 by mrao              #+#    #+#             */
/*   Updated: 2024/08/26 17:33:22 by mrao             ###   ########.fr       */
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
	if (ptr == NULL)
	{
		return (write (1, "(nil)", 5));
	}
	if (write (1, "0x", 2) == -1)
		return (-1);
	len += 2;
	ft_put_ptr_rec((unsigned long long )ptr, &len);
	return (len);
}
