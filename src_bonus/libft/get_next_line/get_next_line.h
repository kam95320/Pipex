/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:37:23 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/06 11:18:42 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1

# endif

# include "../libft_src/libft.h"
# include <stdlib.h>
# include <unistd.h>

/* UTILS */
int		ft_strchr_gnl(const char *s, char c);
char	*ft_memcpy_gnl(char *d, const char *s, size_t n);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);

/* GNL */
char	*get_tmp_str(int fd, char *buf, char *str);
char	*get_current_line(char **str);
char	*get_next_line(int fd);

#endif // GET_NEXT_LINE_H
