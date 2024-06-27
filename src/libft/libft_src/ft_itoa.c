/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:56:13 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/14 14:56:15 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nb_size(long n)
{
	size_t	n_size;

	n_size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		n_size = 1;
	}
	while (n)
	{
		n /= 10;
		n_size++;
	}
	return (n_size);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		i;
	long	nb;

	nb = (long)n;
	i = ft_nb_size(nb);
	tab = malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	tab[i--] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		tab[0] = '-';
	}
	if (nb == 0)
		tab[i] = '0';
	while (nb)
	{
		tab[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (tab);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// 	char *s = ft_itoa(0);
// 	printf("%s", s);
// 	free(s);
// 	return (0);
// }
