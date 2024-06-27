/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:52:10 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/19 15:52:15 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_format_specifier(const char *format, va_list args, int *i)
{
	int	count;

	count = 0;
	if (format[*(i) + 1] == '%')
		count += ft_putchar('%');
	if (format[*(i) + 1] == 'c')
		count += ft_putchar(va_arg(args, int));
	if (format[*(i) + 1] == 's')
		count += get_str(va_arg(args, char *));
	if (format[*(i) + 1] == 'p')
		count += get_address((unsigned long)va_arg(args, void *));
	if (format[*(i) + 1] == 'd')
		count += ft_putnbr(va_arg(args, int));
	if (format[*(i) + 1] == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (format[*(i) + 1] == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int), "0123456789");
	if (format[*(i) + 1] == 'x')
		count += ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef");
	if (format[*(i) + 1] == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	*(i) += 2;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
			count += get_format_specifier(format, args, &i);
		if (format[i] >= 7 && format[i] <= 13)
		{
			ft_putchar(format[i++]);
			count += 1;
		}
		while (format[i] && (format[i] != '%') && !(format[i] >= 7
				&& format[i] <= 13))
			count += ft_putchar(format[i++]);
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// int	ret1;
// 	int	ret2;

// 	// ret1 = printf("%p", ULONG_MAX);
// 	ret2 = ft_printf(" %p %p ", 0, 0);

// 	// printf("\n%i", ret1);
// 	printf("\n%i", ret2);

// 	// printf("%p", ULONG_MAX);
// 	// ft_printf(" %p %p ", 0, 0);

// 	return (0);
// }