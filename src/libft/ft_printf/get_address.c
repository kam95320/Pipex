/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_address.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:46:38 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/28 18:46:39 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_address(unsigned long n, char *base)
{
	int	count;

	if (n == 0)
		return (0);
	count = 0;
	if (n > 15)
		count += put_address((n / 16), base);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	get_address(unsigned long n)
{
	int	count;

	if (n == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	count = ft_putstr("0x");
	count += put_address(n, "0123456789abcdef");
	return (count);
}
