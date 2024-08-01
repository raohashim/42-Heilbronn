/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:59:02 by mrao              #+#    #+#             */
/*   Updated: 2024/08/02 01:29:28 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_conv(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += printf_char(va_arg(ap, int));
	else if (specifier == 's')
		count += printf_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += printf_int(va_arg(ap, int));
	// else if (specifier == 'p')
	// 	count += printf_ptr((va_arg(ap, unsigned long *)));
	// else if (specifier == 'u')
	// 	count += printf_nbr_unsigned(va_arg(ap, unsigned int));
	// else if (specifier == 'x')
	// 	count += printf_int_new((long)va_arg(ap, unsigned int), 16);
	// else if (specifier == 'X')
	// 	count += printf_hex(va_arg(ap, unsigned int), 16);
	// else if (specifier == '%')
	// 	count += printf_char_per('%');
	return (count);
}

// A variadic function is a function in C programming language that can
// take a variable number of arguments.
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
	int		i;
	va_list	ap;

	va_start(ap, format_str);
	char_count = 0;
	i = 0;
	while (format_str[i])
	{
		if (format_str[i] == '%' && format_str[i + 1] != '\0')
		{
			char_count += print_conv(format_str [i + 1], ap);
			i++;
		}
		else
			char_count += printf_char(format_str [i]);
		i++;
	}
	va_end(ap);
	return (char_count);
}

int	main()
{
	int	result;

	result = ft_printf("Hello, %s! You have %c new messages from %d user.\n", "Hashim", '9', -2147483649);
	// result = printf("Hello, %s! You have %c new messages from %d user.\n", "Hashim", '9', -2147483648);

	ft_printf("Printed characters: %d\n", result);
	ft_printf("-------");
	ft_printf("\n");
	result = ft_printf("This is a number: %d and %i this is a string: %s\n", -42, -5322, "test");
	ft_printf("Printed characters: %d\n", result);
	

	return (0);
}
