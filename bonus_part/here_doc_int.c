/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:20:19 by kahoumou          #+#    #+#             */
/*   Updated: 2024/06/18 13:30:10 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pipex_bonus.h"

void	put_text_of_here_doc(char **av, int fd_tmp)
{
	char	*ret;

	while (1)
	{
		ft_putstr_fd("> ", 1);
		ret = get_next_line(0);
		if (!ret)
			continue ;
		if (ft_strncmp(ret, av[2], ft_strlen(av[2])) == 0
			&& ret[ft_strlen(av[2])] == '\n')
		{
			free(ret);
			break ;
		}
		ft_putstr_fd(ret, fd_tmp);
		free(ret);
	}
	close(fd_tmp);
}

void	here_doc_init(t_pipex *pipex, char **av)
{
	int	fd_tmp;

	pipex->here_doc_tmp = "here_doc_tmp.txt";
	fd_tmp = open(pipex->here_doc_tmp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_tmp == -1)
	{
		ft_putstr_fd("error creating temporary file\n", 2);
		exit(EXIT_FAILURE);
	}
	put_text_of_here_doc(av, fd_tmp);
	pipex->fd_in = open_file(pipex->here_doc_tmp, 0);
	if (pipex->fd_in == -1)
	{
		ft_putstr_fd("error opening temporary file\n", 2);
		exit(EXIT_FAILURE);
	}
}
