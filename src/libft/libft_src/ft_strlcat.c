/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:41:31 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/06 11:06:08 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if ((!dst && size == 0) || size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (dst[i] && i < size - 1)
		i++;
	len = i;
	while ((i < size - 1) && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len + ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char b[0xF] = "nyan !";
// 	ft_strlcat(((void*)0), b, 0);

// 	printf("%ld\n%s", ft_strlcat(((void*)0), b, 0), b);
// 	return (0);
// }