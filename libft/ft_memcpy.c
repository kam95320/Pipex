/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:45:31 by kahoumou          #+#    #+#             */
/*   Updated: 2023/11/11 20:02:40 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	if (destination == NULL && source == NULL)
		return (NULL);
	i = 0;
	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	size = (int)size;
	while (size > i)
	{
		dest[i] = src[i];
		i ++;
	}
	return (destination);
}
