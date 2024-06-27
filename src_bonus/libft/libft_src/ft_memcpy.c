/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:47:20 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/03/17 17:31:58 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return ((void *)dest);
}

// char	*ft_memcpy(char *d, const char *s, size_t n)
// {
// 	long long	i;

// 	i = 0;
// 	if (!d || !s)
// 		return (NULL);
// 	while (i < (long long)n)
// 	{
// 		d[i] = s[i];
// 		i++;
// 	}
// 	return (d);
// }