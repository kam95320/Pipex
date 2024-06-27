/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:21:50 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/08 22:22:01 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;

	l_len = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	if (len == 0 && !big)
		return ((char *)little);
	while (*big && *little && len && l_len <= len)
	{
		if (ft_strncmp(big, little, l_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

// #include <bsd/string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	// char haystack[30] = "aaabcabcd";
// 	// char needle[10] = "aabc";
// 	char *empty = (char *)"";

// 	char *ptr = ft_strnstr(empty, "", -1);
// 	char *ptr2 = strnstr(empty, "", -1);
// 	printf("%p\n", (void *)ptr);
// 	printf("%p\n", (void *)ptr2);
// 	return (0);
// }