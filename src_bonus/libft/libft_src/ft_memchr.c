/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:43:43 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/08 23:44:24 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*cs;
	unsigned char		cc;
	unsigned int		i;

	cs = (const unsigned char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (cs[i] == cc)
			return ((void *)cs + i);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char *s = "HJFJLUUUpoil";
// 	char c = 'p';
// 	size_t n = 2;
// 	char *ptr = memchr(s, (int)c, n);
// 	char *ptr2 = ft_memchr(s, (int)c, n);
// 	printf("%s\n%s", ptr, ptr2);
// 	return (0);
// }