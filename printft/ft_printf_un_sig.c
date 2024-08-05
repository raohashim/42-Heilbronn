/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_un_sig.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:35:43 by mrao              #+#    #+#             */
/*   Updated: 2024/08/05 23:27:51 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_fill_str_u(char *str, unsigned int n, int len)
{
	while (len > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
}

char	*ft_itoa_u(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_num_len_u(n);
	str = ft_malloc(len);
	if (!str)
		return (NULL);
	ft_fill_str_u(str, n, len);
	return (str);
}

int	printf_unsigned(unsigned int nbr)
{
	char	*str_itoa;
	int		i;

	i = 0;
	str_itoa = ft_itoa_u(nbr);
	if (!str_itoa)
		return (0);
	i = printf_str(str_itoa);
	free(str_itoa);
	return (i);
}

