/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:59:02 by mrao              #+#    #+#             */
/*   Updated: 2024/08/05 23:31:26 by mrao             ###   ########.fr       */
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

// Your main function
int main() {

    // Test the custom and standard printf with %u
    int test_values[] = {-42, -55, 0, 1, 42, 1234567890};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < num_tests; i++) {
        int value = test_values[i];

        printf("Testing value: %i\n", value);

        // Using custom ft_printf with %u
        printf("Custom ft_printf: ");
        int custom_len = ft_printf("%i\n", value);
        ft_printf("Length: %d\n", custom_len);

        // Using standard printf with %u
        printf("Standard printf: ");
        int standard_len = printf("%i\n", value);
        printf("Length: %d\n", standard_len);

        printf("\n");
    }

    return (0);
}
