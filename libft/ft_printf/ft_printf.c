/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:12:45 by kahoumou          #+#    #+#             */
/*   Updated: 2024/05/30 13:48:50 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format(va_list *args, const char ltr, int *lenght, int *i)
{
	if (ltr == 'c')
		ft_putchar_lenght(va_arg(*args, int), lenght);
	else if (ltr == 'd' || ltr == 'i')
		ft_print_putnbr(va_arg(*args, int), lenght);
	else if (ltr == 's')
		ft_print_putstr(va_arg(*args, char *), lenght);
	else if (ltr == 'p')
		ft_print_pointeur(va_arg(*args, unsigned long long), lenght);
	else if (ltr == 'u')
		ft_print_unsigned(va_arg(*args, unsigned int), lenght);
	else if (ltr == 'X' || ltr == 'x')
		ft_hexadecimal(va_arg(*args, int), lenght, ltr);
	else if (ltr == 'X' || ltr == 'x')
		ft_hexadecimal(va_arg(*args, int), lenght, ltr);
	else if (ltr == '%')
		ft_pourcentage(lenght);
	else
		(*i)--;
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i += 1;
			ft_format(&args, string[i], &length, &i);
			i += 1;
		}
		else
		{
			ft_putchar_lenght((char)string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
