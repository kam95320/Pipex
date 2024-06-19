/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:15:54 by kahoumou          #+#    #+#             */
/*   Updated: 2024/06/03 15:38:49 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_gnl_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_gnl_strdup(const char *src)
{
	int		len;
	char	*dup;
	int		i;

	i = 0;
	len = ft_gnl_strlen(src);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

char	ft_gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_gnl_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_gnl_strlen(src));
}

char	*ft_gnl_substr(char const *s, int start, size_t len)
{
	size_t	actual_len;
	char	*substr;

	if (!s || start >= ft_gnl_strlen(s))
		return (ft_gnl_strdup(""));
	actual_len = ft_gnl_strlen(s + start);
	if (actual_len < len)
		len = actual_len;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_gnl_strlcpy(substr, s + start, len + 1);
	return (substr);
}
