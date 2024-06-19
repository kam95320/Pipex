/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:04:36 by kahoumou          #+#    #+#             */
/*   Updated: 2023/11/15 12:51:21 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include"libft.h"

char	*ft_strjoin(char const *tab, char const *sep)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!tab)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(tab) + ft_strlen(sep) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		str[i] = tab[i];
		i++;
	}
	j = 0;
	while (sep[j])
	{
		str[i + j] = sep[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
