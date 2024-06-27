/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:22:08 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/11/06 11:41:51 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	n;

	n = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * sign);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_atoi("+1"));
// 	printf("%d\n", ft_atoi("a1"));
// 	printf("%d\n", ft_atoi("-1"));
// 	printf("%d\n", ft_atoi("0"));
// 	printf("%d\n", ft_atoi("+42lyon"));
// 	printf("%d\n", ft_atoi("-1325632167"));
// 	printf("%d\n", ft_atoi("-100"));
// 	printf("%d\n", ft_atoi("\t---+2147483648"));
// 	printf("%d\n", ft_atoi("\v2147483647"));
// }