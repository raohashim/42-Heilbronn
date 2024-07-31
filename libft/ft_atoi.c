/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 06:37:08 by mrao              #+#    #+#             */
/*   Updated: 2024/07/15 09:25:38 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	num;

	neg = 0;
	num = 0;
	while (*nptr != '\0' && ((*nptr >= 9 && *nptr <= 13) || *nptr == 32))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = 1;
		nptr++;
	}
	while (*nptr != '\0' && (*nptr >= '0' && *nptr <= '9'))
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	if (neg)
		num = num * -1;
	return (num);
}
