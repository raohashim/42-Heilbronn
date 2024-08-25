/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:59:02 by mrao              #+#    #+#             */
/*   Updated: 2024/08/25 18:14:13 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_conv(char specifier, va_list ap)
{
	if (specifier == 'c')
		return (printf_char(va_arg(ap, int)));
	else if (specifier == 's')
		return (printf_str(va_arg(ap, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (printf_int(va_arg(ap, int)));
	else if (specifier == 'p')
		return (printf_ptr((va_arg(ap, void *))));
	else if (specifier == 'u')
		return (printf_int(va_arg(ap, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (printf_hex((long)va_arg(ap, unsigned int), specifier));
	else if (specifier == '%')
		return (write (1, "%", 1));
	return (-1);
}

// A variadic function is a function in C programming language that can
// take a variable number of arguments.><<<|<<<||<<<
// Variadic functions are supported in C through a special set of macros
// va ----> Vector Argument
// va_list ap -> ap in a variadic function is a pointer to a -> va_list object
// va_start(va_list ap, last) -> Initializer Vector 
// 			   (initialize va_list obj, to access each arguments)
//             It makes ap to poin to the 1st argument
// va_arg(va_list ap, type) -> Takes the next argument
// va_copy(va_list dst, va_list src) ->
// va_end(va_list ap) -> End retriving argumetns (free up space)
// ... -> Ellipsis means function can take variable no. of arguments of any type
int	ft_printf(const char *format_str, ...)
{
	int		char_count;
	int		flag;
	va_list	ap;

	va_start(ap, format_str);
	char_count = 0;
	while (*format_str)
	{
		if (*format_str == '%')
		{
			flag = print_conv(*(++format_str), ap);
			if (flag == -1)
				return (-1);
			char_count += flag;
		}
		else
		{
			if (write(1, format_str, 1) == -1)
				return (-1);
			char_count++;
		}
		format_str++;
	}
	va_end(ap);
	return (char_count);
}
