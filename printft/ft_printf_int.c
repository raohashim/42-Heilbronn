/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 07:19:22 by mrao              #+#    #+#             */
/*   Updated: 2024/08/05 23:31:47 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_fill_str(char *str, int n, int len)
{
	int	is_neg;

	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n = n * -1;
	}
	while (len > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (is_neg)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_num_len(n);
	str = ft_malloc(len);
	if (!str)
		return (NULL);
	ft_fill_str(str, n, len);
	return (str);
}

int	printf_int(int d)
{
	char	*str_itoa;
	int		i;

	i = 0;
	str_itoa = ft_itoa(d);
	if (!str_itoa)
		return (0);
	i = printf_str(str_itoa);
	free(str_itoa);
	return (i);
}

// int	printf_int_new(int d, int base)
// {
// 	int		count;
// 	char	*hex_digits;

// 	if (d == -2147483648)
// 		return (ft_strdup("-2147483648"));
// 	hex_digits = "0123456789abcdef";
// 	if (d < 0)
// 	{
// 		write (1, "-", 1);
// 		d = d * -1;
// 		return (printf_int_new(d, base) + 1);
// 	}
// 	else if (d < base)
// 		return (printf_char(hex_digits[d]));
// 	else
// 	{
// 		count = printf_int_new(d / base, base);
// 		return (count + printf_int_new(d % base, base));
// 	}
// }
