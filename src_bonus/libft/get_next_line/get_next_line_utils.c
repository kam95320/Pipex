/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:37:11 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/06 11:18:11 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_gnl(const char *s, char c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s)
	{
		if (*s == uc)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_memcpy_gnl(char *d, const char *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!d || !s)
		return (NULL);
	while ((i + 7) < n)
	{
		*(long long *)(d + i) = *(const long long *)(s + i);
		i += 8;
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	t_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	t_len = len1 + len2;
	str = malloc(sizeof(char) * (t_len + 1));
	if (!str)
		return (NULL);
	ft_memcpy_gnl(str, s1, (len1));
	ft_memcpy_gnl((str + len1), s2, (len2 + 1));
	str[len1 + len2] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s || *s == '\0')
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (NULL);
	if (start + len > s_len)
		len = s_len - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_memcpy_gnl(str, s + start, (len));
	str[len] = '\0';
	return (str);
}
