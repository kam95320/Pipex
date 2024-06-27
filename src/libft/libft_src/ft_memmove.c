/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:57:08 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/11 21:21:01 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	return ((void *)dest);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	int		i;
// 	char	dest[100];
// 	char tab[100];
// 	char	*src;

// 	i = 0;
// 	src = "Hello";
// 	size_t n = 3;
// 	memmove(dest, src, n);
// 	while (i < 10)
// 		printf("%c", dest[i++]);
// 	printf("\n%p\n", memmove(dest, src, n));

// 	ft_memmove(tab, src, n);
// 	while (i < 10)
// 		printf("%c", tab[i++]);
// 	printf("\n%p", ft_memmove(tab, src, n));
// 	return (0);
// }
