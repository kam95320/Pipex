/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:19:36 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/11 17:03:55 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcount(const char *str, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && i < ft_strlen(str))
		{
			if (str[i + 1] == '\0' || str[i + 1] == c)
				count++;
			i++;
		}
	}
	return (count);
}

static char	**ft_cpy_tab(const char *str, char **tab, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i] && k < ft_wcount(str, c))
	{
		j = 0;
		while (str[i] != c && str[i] != '\0')
		{
			tab[k][j++] = str[i++];
			if (str[i] == c || str[i] == '\0')
			{
				tab[k][j] = '\0';
				k++;
			}
		}
		while (str[i] == c)
			i++;
	}
	return (tab);
}

static char	**ft_split_words(char const *s, char c, int count, char **tab)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (count < ft_wcount(s, c))
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i++])
			len++;
		tab[count] = malloc(sizeof(char) * (len + 1));
		if (!tab[count])
			return (clear_tab(tab), NULL);
		tab[count++][0] = '\0';
	}
	tab[ft_wcount(s, c)] = NULL;
	return (ft_cpy_tab(s, tab, c));
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**tab;

	if (!s || !c)
		return (NULL);
	count = 0;
	tab = malloc(sizeof(char *) * (ft_wcount(s, c) + 1));
	if (!tab)
		return (clear_tab(tab), NULL);
	return (ft_split_words(s, c, count, tab));
}
