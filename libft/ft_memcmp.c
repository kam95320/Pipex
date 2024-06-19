/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:47:19 by kahoumou          #+#    #+#             */
/*   Updated: 2023/11/13 17:41:04 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned int	i;
	unsigned int	sz;

	s1 = (unsigned char *)pointer1;
	s2 = (unsigned char *)pointer2;
	sz = (unsigned int)size;
	i = 0;
	if (sz == 0)
		return (0);
	while (i < sz -1)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i ++;
	}
	return (s1[i] - s2[i]);
}
