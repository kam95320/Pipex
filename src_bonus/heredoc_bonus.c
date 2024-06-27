/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:28:49 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/01 17:39:41 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	end_heredoc(int fd, char *line, t_data *data)
{
	if (line)
	{
		free(line);
		get_next_line(fd);
	}
	close(fd);
	data->in = open(HEREDOC, O_RDONLY);
	if (data->in == -1)
	{
		unlink(HEREDOC);
		check_error(HEREDOC, 0, data);
	}
}

void	get_line(int fd, char *line)
{
	write(fd, line, ft_strlen(line));
	free(line);
	line = 0;
}

void	get_heredoc(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(HEREDOC, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (fd == -1)
		check_error(HEREDOC, 0, data);
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		line = get_next_line(0);
		if (!line || (ft_strncmp(data->limiter, line,
					ft_strlen(data->limiter)) == 0
				&& (ft_strlen(data->limiter) == ft_strlen(line) - 1
					&& line[ft_strlen(line) - 1 == '\n'])))
			break ;
		get_line(fd, line);
	}
	end_heredoc(fd, line, data);
}
