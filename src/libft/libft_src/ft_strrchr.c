/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:09:13 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/08 18:10:55 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	while (i-- > 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char s[] = "tripouille";
// 	printf("%s\n", ft_strrchr(s, 0));
// 	return (0);
// }