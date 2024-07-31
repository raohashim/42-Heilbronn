/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:59:02 by mrao              #+#    #+#             */
/*   Updated: 2024/07/31 09:11:44 by mrao             ###   ########.fr       */
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
	// 	count += printf_ptr((unsigned long)(va_arg(ap, void *)));
	// else if (specifier == 'u')
	// 	count += printf_nbr_unsigned(va_arg(ap, unsigned int));
	// else if (specifier == 'x')
	// 	count += printf_hex(va_arg(ap, unsigned int), 0);
	// else if (specifier == 'X')
	// 	count += printf_hex(va_arg(ap, unsigned int), 1);
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

	result = ft_printf("Hello, %s! You have %c new messages.\n", "Hashim", '9');
	printf("Printed characters: %d\n", result);

	// result = ft_printf("This is a number: %d and this is a string: %s\n", 42, "test");
	// printf("Printed characters: %d\n", result);

	return (0);
}
