/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:23:45 by kahoumou          #+#    #+#             */
/*   Updated: 2024/06/05 15:36:21 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pipex.h"

void	child_process(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[1], 0);
	if (fd == -1)
	{
		perror("pipex: open_file");
		exit(EXIT_FAILURE);
	}
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(fd);
	close(p_fd[0]);
	close(p_fd[1]);
	exec(av[2], env);
}

void	child2_process(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[4], 1);
	if (fd == -1)
	{
		perror("pipex: open_file");
		exit(EXIT_FAILURE);
	}
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(fd);
	close(p_fd[0]);
	close(p_fd[1]);
	exec(av[3], env);
}

void	close_and_wait(int *fd, pid_t id1, pid_t id2)
{
	int	status;

	close(fd[0]);
	close(fd[1]);
	waitpid(id1, &status, 0);
	waitpid(id2, &status, 0);
}

void	open_id_process(char *argv[], int *fd, char *env[])
{
	pid_t	id1;
	pid_t	id2;

	if (pipe(fd) == -1)
	{
		exit(EXIT_FAILURE);
	}
	id1 = fork();
	if (id1 == -1)
	{
		exit(EXIT_FAILURE);
	}
	if (id1 == 0)
		child_process(argv, fd, env);
	id2 = fork();
	if (id2 == -1)
	{
		exit(EXIT_FAILURE);
	}
	if (id2 == 0)
		child2_process(argv, fd, env);
	close_and_wait(fd, id1, id2);
}

int	main(int argc, char *argv[], char *env[])
{
	int	fd1[2];

	if (argc != 5)
		exit_handler(1);
	open_id_process(argv, fd1, env);
	return (0);
}
