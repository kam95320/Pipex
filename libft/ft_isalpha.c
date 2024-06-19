/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:11:41 by kahoumou          #+#    #+#             */
/*   Updated: 2023/11/06 16:18:40 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<ctype.h>
#include<stdio.h>

int	ft_isalpha(int character)
{
	if (character >= 'a' && character <= 'z')
		return (1024);
	else if (character >= 'A' && character <= 'Z')
		return (1024);
	else
		return (0);
}
