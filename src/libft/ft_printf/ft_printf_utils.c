/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:34:44 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/25 18:36:31 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}

int	get_str(char *s)
{
	if (s != NULL)
		return (ft_putstr(s));
	return (ft_putstr("(null)"));
}

int	ft_putnbr(int n)
{
	char	nb;
	int		count;

	count = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		count++;
	}
	if (n >= 10)
		count += ft_putnbr((n / 10));
	nb = (n % 10) + '0';
	count += ft_putchar(nb);
	return (count);
}
