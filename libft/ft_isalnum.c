/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:53:20 by kahoumou          #+#    #+#             */
/*   Updated: 2023/11/25 17:19:22 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int character)
{
	if (character >= 'a' && character <= 'z')
		return (8);
	else if (character >= 'A' && character <= 'Z')
		return (8);
	else if (character >= '0' && character <= '9')
		return (8);
	else
		return (0);
}
