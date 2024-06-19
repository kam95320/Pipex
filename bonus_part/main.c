/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:05:01 by kahoumou          #+#    #+#             */
/*   Updated: 2024/06/18 13:17:21 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pipex_bonus.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	handle_here_doc(t_pipex *pipex, int ac, char **av)
{
	if (ac < 6)
		exit_handler(1);
	pipex->fd_out = open_file(av[ac - 1], 2);
	here_doc_init(pipex, av);
	dup2(pipex->fd_in, 0);
}

void	handle_infile_outfile(t_pipex *pipex, int ac, char **av)
{
	pipex->fd_in = open_file(av[1], 0);
	pipex->fd_out = open_file(av[ac - 1], 1);
	dup2(pipex->fd_in, 0);
}

void	process_commands(t_pipex *pipex, int ac, char **av, int start_index)
{
	int	i;

	i = start_index;
	while (i < ac - 1)
		add_cmd(pipex, av[i++]);
	execute_commands(pipex);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac < 5)
		exit_handler(1);
	pipex.env = env;
	pipex.cmds = NULL;
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
	{
		handle_here_doc(&pipex, ac, av);
		process_commands(&pipex, ac, av, 3);
	}
	else
	{
		handle_infile_outfile(&pipex, ac, av);
		process_commands(&pipex, ac, av, 2);
	}
	unlink(pipex.here_doc_tmp);
	free_cmds(pipex.cmds);
	close(pipex.fd_in);
	close(pipex.fd_out);
	return (0);
}
