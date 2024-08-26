/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:51:23 by mrao              #+#    #+#             */
/*   Updated: 2024/08/26 17:15:07 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *input, ...);
int		printf_char(char c);
int		printf_str(char *str);
int		printf_int(long d);
int		printf_ptr(void *ptr);
int		printf_unsigned(unsigned int nbr);
int		printf_hex(unsigned long hxd, char symbol);

#endif