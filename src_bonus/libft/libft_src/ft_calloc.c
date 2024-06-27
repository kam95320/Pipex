/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:08:43 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/09 20:08:45 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	t_size;
	void	*array;

	t_size = nmemb * size;
	if (nmemb != 0 && t_size / nmemb != size)
		return (NULL);
	array = malloc(t_size);
	if (!array)
		return (NULL);
	ft_memset(array, 0, t_size);
	return ((void *)array);
}
