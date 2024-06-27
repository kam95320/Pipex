/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:47:15 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/28 18:47:16 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n == UINT_MAX)
	{
		if (base[10] == 'a')
			ft_putstr("ffffffff");
		else if (base[10] == 'A')
			ft_putstr("FFFFFFFF");
		return (8);
	}
	if (n > 15)
		count += ft_putnbr_hex((n / 16), base);
	count += ft_putchar(base[n % 16]);
	return (count);
}
