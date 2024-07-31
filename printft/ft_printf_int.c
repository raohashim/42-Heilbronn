/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 07:19:22 by mrao              #+#    #+#             */
/*   Updated: 2024/07/31 17:37:32 by mrao             ###   ########.fr       */
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

char	*ft_itoa_malloc(int len)
{
	char	*mem;

	mem = malloc(len + 1);
	if (!mem)
		return (NULL);
	mem[len] = '\0';
	return (mem);
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
	str = ft_itoa_malloc(len);
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
