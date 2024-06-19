/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:25:26 by kahoumou          #+#    #+#             */
/*   Updated: 2024/05/31 21:24:13 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_gnl_strlen(const char *str);
char	*ft_gnl_strjoin(char const *tab, char const *sep);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strdup(char *src);
char	*ft_gnl_substr(char const *s, int start, size_t len);
char	ft_gnl_strlcpy(char *dst, const char *src, size_t size);
char	*get_next_line(int fd);

#endif
