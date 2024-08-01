/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:51:23 by mrao              #+#    #+#             */
/*   Updated: 2024/08/02 01:28:36 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

// To be removed only for testing
# include <stdio.h>

char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char	*str);
int		ft_printf(const char *input, ...);
int		printf_char(int c);
int		printf_str(char *str);
int		printf_int(int d);
// int		printf_ptr(unsigned long ptr);
// int		printf_int_new(int d, int base);

#endif