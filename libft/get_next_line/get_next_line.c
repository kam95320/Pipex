/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:24:59 by kahoumou          #+#    #+#             */
/*   Updated: 2024/05/31 21:29:27 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_gnl_strjoin(const char *s1, const char *s2)
{
	int		len1;
	int		len2;
	char	*joined;

	int (i) = 0;
	int (j) = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_gnl_strlen(s1);
	len2 = ft_gnl_strlen(s2);
	joined = malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	while (i < len1)
	{
		joined[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		joined[len1 + j] = s2[j];
		j++;
	}
	joined[len1 + len2] = '\0';
	return (joined);
}

static char	*ft_take_line(char *next, char *line, int fd)
{
	static char	*static_tmp;
	int			rd;

	rd = 1;
	while (rd != 0)
	{
		rd = read(fd, line, BUFFER_SIZE);
		if (rd == -1)
			return (0);
		else if (rd == 0)
			break ;
		line[rd] = '\0';
		if (!next)
			next = ft_gnl_strdup("");
		static_tmp = next;
		next = ft_gnl_strjoin(static_tmp, line);
		if (!next)
			return (free(static_tmp), NULL);
		free(static_tmp);
		static_tmp = NULL;
		if (ft_gnl_strchr(line, '\n'))
			break ;
	}
	return (next);
}

static char	*ft_one_line(char *all_lines)
{
	char	*just_line;
	size_t	i;

	i = 0;
	while (all_lines[i] != '\n' && all_lines[i] != '\0')
		i++;
	if (all_lines[i] == '\0')
		return (0);
	just_line = ft_gnl_substr(all_lines, i + 1, ft_gnl_strlen(all_lines) - i);
	if (just_line && *just_line == '\0')
	{
		free(just_line);
		just_line = NULL;
	}
	all_lines[i + 1] = '\0';
	return (just_line);
}

char	*get_next_line(int fd)
{
	char		*get;
	static char	*next;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
	{
		perror("Error allocating memory for line");
		return (NULL);
	}
	get = ft_take_line(next, line, fd);
	free(line);
	line = NULL;
	if (!get)
		return (NULL);
	next = ft_one_line(get);
	return (get);
}
