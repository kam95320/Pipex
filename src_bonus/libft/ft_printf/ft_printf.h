/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:45:08 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/29 12:56:34 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(unsigned char c);
int	ft_putstr(const char *s);
int	get_str(char *s);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n, char *base);
int	ft_putnbr_hex(unsigned int n, char *base);
int	put_address(unsigned long n, char *base);
int	get_address(unsigned long n);
int	get_format_specifier(const char *format, va_list args, int *i);
int	ft_printf(const char *format, ...);

#endif // FT_PRINTF_H_
