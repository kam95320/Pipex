/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:02:39 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/09 15:45:06 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char s[] = "Hello";
// 	size_t n = 1;
// 	bzero(s, n);
// 	printf("%s", s);
// 	return 0;
// }
