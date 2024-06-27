/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:30:24 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/06 12:40:21 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char src[] = "coucou";
// 	char dest[10];
// 	memset(dest, 'A', 10);
// 	int i = 0;
// 	while (dest[i])
// 		printf("%c\n", dest[i++]);
// 	// printf("libc : %s, return (: %d\n ", dest, strlcpy(dest, src, 1)));
// 	i = 0;
// 	ft_strlcpy(dest, src, 2);
// 	while (dest[i])
// 		printf("%c\n", dest[i++]);
// 	return (0);
// }