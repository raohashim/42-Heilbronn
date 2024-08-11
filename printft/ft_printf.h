/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:51:23 by mrao              #+#    #+#             */
/*   Updated: 2024/08/10 08:25:09 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

// To be removed only for testing
# include <stdio.h>
# include <stdlib.h>

char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char	*str);
char	*ft_malloc(int len);
int		ft_printf(const char *input, ...);
int		printf_char(int c);
int		printf_str(char *str);
int		printf_int(int d);
int		printf_ptr(unsigned long long num);
int		printf_unsigned(unsigned int nbr);
int		printf_hex(unsigned int hxd, char symbol);

#endif