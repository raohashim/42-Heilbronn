/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 06:50:55 by mrao              #+#    #+#             */
/*   Updated: 2024/07/14 15:20:38 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	char	*str;

	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
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
