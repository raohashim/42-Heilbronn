/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 08:51:26 by mrao              #+#    #+#             */
/*   Updated: 2024/07/14 15:23:35 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str_join;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = (int)ft_strlen(s1);
	j = (int)ft_strlen(s2);
	str_join = malloc((i + j + 1) * sizeof(char));
	if (!str_join)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		str_join[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
	{
		str_join[i] = s2[j];
		i++;
	}
	str_join[i] = '\0';
	return (str_join);
}
