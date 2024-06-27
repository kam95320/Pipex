/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:50:50 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/08 16:40:53 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (!(c >= 'a' && c <= 'z'))
		return (c);
	c -= 32;
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main()
// {
// 	char l = 'B';
// 	char u = ft_toupper(l);
// 	printf("%c\n", u);
// 	return 0;
// }