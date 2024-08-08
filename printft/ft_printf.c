/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:59:02 by mrao              #+#    #+#             */
/*   Updated: 2024/08/08 17:31:03 by mrao             ###   ########.fr       */
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
	else if (specifier == 'p')
		count += printf_ptr((va_arg(ap, unsigned long long)));
	else if (specifier == 'u')
		count += printf_unsigned(va_arg(ap, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += printf_hex((long)va_arg(ap, unsigned int), specifier);
	else if (specifier == '%')
		count += write (1, "%", 1);
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

#include <stdio.h>
#include <limits.h>

int	main()
{
	unsigned int	num;
	int				cnt;
	int				cnt_print;

	// Basic positive number
	num = 962927349;
	cnt_print = printf("Standard %% %% %% %% printf: Hexadecimal lowercase: %x\n", num);
	cnt = ft_printf("ft_printf       %% %% %% %%: Hexadecimal lowercase: %x\n", num);
	ft_printf("Char count - printf: %d, ft_printf: %d\n", cnt_print, cnt);

	cnt_print = printf("Standard printf: Hexadecimal uppercase: %X\n", num);
	cnt = ft_printf("ft_printf      : Hexadecimal uppercase: %X\n", num);
	ft_printf("Char count - printf: %d, ft_printf: %d\n", cnt_print, cnt);

	ft_printf("---------------------\n");

	// Testing zero
	num = 0;
	cnt_print = printf("Standard printf: Hexadecimal lowercase: %x\n", num);
	cnt = ft_printf("ft_printf      : Hexadecimal lowercase: %x\n", num);
	ft_printf("Char count - printf: %d, ft_printf: %d\n", cnt_print, cnt);

	cnt_print = printf("Standard printf: Hexadecimal uppercase: %X\n", num);
	cnt = ft_printf("ft_printf      : Hexadecimal uppercase: %X\n", num);
	ft_printf("Char count - printf: %d, ft_printf: %d\n", cnt_print, cnt);

	ft_printf("---------------------\n");

	// Maximum unsigned int value
	num = UINT_MAX;
	cnt_print = printf("Standard printf: Hexadecimal lowercase: %x\n", num);
	cnt = ft_printf("ft_printf      : Hexadecimal lowercase: %x\n", num);
	ft_printf("Char count - printf: %d, ft_printf: %d\n", cnt_print, cnt);

	cnt_print = printf("Standard printf: Hexadecimal uppercase: %X\n", num);
	cnt = ft_printf("ft_printf      : Hexadecimal uppercase: %X\n", num);
	ft_printf("Char count - printf: %d, ft_printf: %d\n", cnt_print, cnt);

	ft_printf("---------------------\n");

	// Negative value treated as unsigned
	num = -1;
	cnt_print = printf("Standard printf: Hexadecimal lowercase: %x\n", num);
	cnt = ft_printf("ft_printf      : Hexadecimal lowercase: %x\n", num);
	ft_printf("Char count - printf: %d, ft_printf: %d\n", cnt_print, cnt);

	cnt_print = printf("Standard printf: Hexadecimal uppercase: %X\n", num);
	cnt = ft_printf("ft_printf      : Hexadecimal uppercase: %X\n", num);
	ft_printf("Char count - printf: %d, ft_printf: %d\n", cnt_print, cnt);

	ft_printf("---------------------\n");

	// Testing with specific edge values
	num = 16;
	cnt_print = printf("Standard printf: Hexadecimal lowercase: %x\n", num);
	cnt = ft_printf("ft_printf      : Hexadecimal lowercase: %x\n", num);
	ft_printf("Char count - printf: %d, ft_printf: %d\n", cnt_print, cnt);

	num = 15;
	cnt_print = printf("Standard printf: Hexadecimal lowercase: %x\n", num);
	cnt = ft_printf("ft_printf      : Hexadecimal lowercase: %x\n", num);
	ft_printf("Char count - printf: %d, ft_printf: %d\n", cnt_print, cnt);

	num = 1;
	cnt_print = printf("Standard printf: Hexadecimal lowercase: %x\n", num);
	cnt = ft_printf("ft_printf      : Hexadecimal lowercase: %x\n", num);
	ft_printf("Char count - printf: %d, ft_printf: %d\n", cnt_print, cnt);

	return (0);
}