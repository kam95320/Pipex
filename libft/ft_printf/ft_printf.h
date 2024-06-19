/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:03:07 by kahoumou          #+#    #+#             */
/*   Updated: 2024/05/30 13:48:50 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_print_putstr(char *str, int *lenght);
void	ft_print_putnbr(int nb, int *lenght);
void	ft_hexadecimal(unsigned int nb, int *lenght, char hex);
void	ft_pourcentage(int *lenght);
void	ft_print_unsigned(unsigned int nb, int *lenght);
void	ft_print_pointeur(size_t p, int *lenght);
void	ft_putchar_lenght(char c, int *lenght);
#endif
