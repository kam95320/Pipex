/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:11:55 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/26 16:35:30 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_pipes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->pipes)
	{
		close(data->fd[i][0]);
		close(data->fd[i][1]);
	}
}

void	clear_child(t_data *data)
{
	close_files(data);
	if (data->cmd.paths)
		clear_tab(data->cmd.paths);
	if (data->fd)
		clear_int_tab(data->fd, data->pipes);
	if (data->epath)
		free(data->epath);
	if (data->pid)
		free(data->pid);
	exit (1);
}

void	close_files(t_data *data)
{
	if (data->in_err == -1)
		close(data->in);
	if (data->out_err == -1)
		close(data->out);
	if (data->here_doc)
		unlink(HEREDOC);
}

void	clear_all(t_data *data)
{
	close_files(data);
	if (data->cmd.paths)
		clear_tab(data->cmd.paths);
	if (data->fd)
		clear_int_tab(data->fd, data->pipes);
	if (data->epath)
		free(data->epath);
	if (data->pid)
		free(data->pid);
}
