/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:52:01 by kahoumou          #+#    #+#             */
/*   Updated: 2023/11/22 14:11:47 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <stddef.h>
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen((char *)to_find) == 0)
		return ((char *)str);
	while (i < size && str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j) < size)
		{
			if (to_find[j + 1] == '\0')
				return (i + (char *)str);
			j++;
		}
		i++;
	}
	return (0);
}
