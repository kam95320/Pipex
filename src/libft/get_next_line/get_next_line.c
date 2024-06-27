/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:36:49 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/06 11:18:13 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_tmp_str(int fd, char *buf, char *str)
{
	int	bytes_read;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		if (!str)
			str = ft_strdup(buf);
		else
			str = ft_strjoin_gnl(str, buf);
		if (!str)
			break ;
		if (ft_strchr_gnl(buf, '\n'))
			break ;
	}
	return (str);
}

char	*get_current_line(char **str)
{
	size_t	i;
	size_t	len;
	char	*line;
	char	*tmp;

	i = 0;
	len = ft_strlen(*str);
	while (((*str)[i] != '\n' && i < len))
		i++;
	if ((*str)[i] == '\n')
		i++;
	line = ft_substr_gnl(*str, 0, i);
	if (!line)
	{
		free(*str);
		return (NULL);
	}
	tmp = ft_strdup(*(str) + i);
	free(*str);
	*str = ft_strdup(tmp);
	free(tmp);
	if (!*str)
		return (free(line), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buf[2];
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	str = get_tmp_str(fd, buf, str);
	if (!str)
		return (NULL);
	line = get_current_line(&str);
	if (!line)
		return (NULL);
	if (line[0] == '\0')
	{
		free(str);
		free(line);
		return (NULL);
	}
	return (line);
}

// #include <sys/stat.h>
// #include <fcntl.h>

// int main(void)
// {
// 	int fd;

// 	fd = open("get_next_line.h",O_RDONLY);
// 	if (!fd)
// 		return (0);
// 	else
// 		write (1, "ok\n", 3);
// 	return 0;
// }