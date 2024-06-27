/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:13:14 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/08 17:18:54 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char *s = "Hello";
// 	char l = 'j';
// 	char *z = strchr(s, l);
// 	printf("%p\n", ft_strchr(s, 0));
// 	printf("%p\n", (void *)z);
// 	return (0);
// }