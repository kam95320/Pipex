/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:18:41 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/24 13:16:47 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_get_tab(char const *s1, int i, int j)
{
	int		k;
	char	*s2;

	k = 0;
	if (i == j)
	{
		s2 = malloc(sizeof(char) * 2);
		if (!s2)
			return (NULL);
		s2[k++] = s1[i];
	}
	else
	{
		s2 = malloc(sizeof(char) * (j - i + 2));
		if (!s2)
			return (NULL);
		while (i <= j)
			s2[k++] = s1[i++];
	}
	s2[k] = '\0';
	return (s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (is_in_set(s1[i], set))
		i++;
	while (is_in_set(s1[j], set))
		j--;
	if (!s1 || !*s1 || i > j)
		return (ft_strdup(""));
	return (ft_get_tab(s1, i, j));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s = ft_strtrim("abcdba", "acb");
// 	printf("%s", s);
// 	free(s);
// 	return (0);
// }