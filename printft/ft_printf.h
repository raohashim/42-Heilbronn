/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:51:23 by mrao              #+#    #+#             */
/*   Updated: 2024/07/31 17:42:10 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

// To be removed only for testing
# include <stdio.h>

int ft_printf(const char *input, ...);
int printf_char(int c);
int printf_str(char *str);
int printf_int(int d);
char    *ft_strdup(const char	*str);

#endif