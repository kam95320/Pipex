/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:09:52 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/06 16:49:41 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned int	i;

	p = s;
	i = 0;
	while (i < n)
		p[i++] = (unsigned char)c;
	return (s);
}	

// #include <string.h>
// #include <stdio.h>

// int main()
// {
// 	int i = 0;
// 	char tab[100];
// 	int c = 9;
// 	size_t n = 7;
// 	memset(tab, c, n);
// 	while (i < 10)
// 		printf("%d", tab[i++]);
// 	printf("\n%p\n", memset(tab, c, n));

// 	ft_memset(tab, c, n);
// 	while (i < 10)
// 		printf("%d", tab[i++]);
// 	printf("\n%p", ft_memset(tab, c, n));
// 	return (0);
// }