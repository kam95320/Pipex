/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:12:25 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/09 18:12:55 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cs1;
	const unsigned char	*cs2;
	size_t				i;
	int					res;

	cs1 = (const unsigned char *)s1;
	cs2 = (const unsigned char *)s2;
	i = 0;
	res = 0;
	while (i < n)
	{
		res = cs1[i] - cs2[i];
		if (res)
			return (res);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	s2[] = {0, 0, 127, 0};
// 	char	s3[] = {0, 0, 42, 0};
// 	printf("%d\n", memcmp(s2, s3, 4));
// 	printf("%d", ft_memcmp(s2, s3, 4));
// 	return (0);
// }
