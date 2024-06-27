/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:58:18 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/06 18:18:41 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	t_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (t_len + 1));
	if (!str)
		return (NULL);
	str[0] = 0;
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, (t_len + 1));
	str[t_len] = '\0';
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	char *s1 = "Hello ";
// 	char *s2 = "Bonjour";
// 	char *str = ft_strjoin(s1, s2);
// 	printf("%s", str);
// 	free(str);
// 	return (0);
// }
