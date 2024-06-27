/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:51:41 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/01 17:36:35 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_pids(t_data *data)
{
	data->pid = malloc(sizeof(int) * data->cmd.n);
	if (!data->pid)
		print_error("malloc", 0, data);
}

void	get_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->pipes)
	{
		if (pipe(data->fd[i]) < 0)
		{
			while (i--)
			{
				close(data->fd[i][0]);
				close(data->fd[i][1]);
			}
			print_error("pipe", EXIT_FAILURE, data);
		}
		i++;
	}
}

void	get_fd(t_data *data)
{
	int	i;

	i = -1;
	data->fd = malloc(sizeof(int *) * data->pipes);
	if (!data->fd)
		print_error("malloc", 0, data);
	while (++i < data->pipes)
	{
		data->fd[i] = malloc(sizeof(int) * 2);
		if (!data->fd[i])
			print_error("malloc", 0, data);
	}
}

void	init_all(t_data *data)
{
	data->i = -1;
	data->in = -1;
	data->out = -1;
	data->cmd.n = 0;
	data->cmd.paths = 0;
	data->cmd.args = 0;
	data->cmd.c_path = 0;
	data->in_err = -1;
	data->out_err = -1;
}

t_data	init_data(int ac, char **av, char **envp)
{
	t_data	data;

	init_all(&data);
	get_files(ac, av, &data);
	get_cmds(ac, &data, envp);
	get_fd(&data);
	get_pipes(&data);
	get_pids(&data);
	return (data);
}
