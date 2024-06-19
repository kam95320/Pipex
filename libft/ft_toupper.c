/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:15:32 by kahoumou          #+#    #+#             */
/*   Updated: 2023/11/12 15:29:30 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_toupper(int character)
{
	if (character >= 'a' && character <= 'z')
		return (character - 32);
	else
		return (character);
}