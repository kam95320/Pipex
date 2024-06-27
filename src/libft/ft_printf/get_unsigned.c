/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:46:56 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/28 18:46:57 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n > UINT_MAX)
		return (0);
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n == UINT_MAX)
	{
		ft_putstr("4294967295");
		return (10);
	}
	if (n > 9)
		count += ft_putnbr_unsigned((n / 10), base);
	count += ft_putchar(base[n % 10]);
	return (count);
}
