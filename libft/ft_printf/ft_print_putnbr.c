/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:43:33 by kahoumou          #+#    #+#             */
/*   Updated: 2024/05/30 13:48:50 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_putnbr(int nb, int *lenght)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*lenght) += 11;
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar_lenght('-', lenght);
	}
	if (nb > 9)
		ft_print_putnbr((nb / 10), lenght);
	ft_putchar_lenght(nb % 10 + '0', lenght);
}
