/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointeur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:54:31 by kahoumou          #+#    #+#             */
/*   Updated: 2023/12/04 17:07:53 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <unistd.h>

void	ft_print_pointeur(size_t p, int *lenght)
{
	char	adr[25];
	char	*str;
	int		i;

	if (p == 0)
	{
		write(1, "(nil)", 5);
		(*lenght) += 5;
		return ;
	}
	str = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*lenght) += 2;
	while (p != 0)
	{
		adr[i] = str[p % 16];
		p = p / 16;
		i++;
	}
	while (i--)
		ft_putchar_lenght(adr[i], lenght);
}
