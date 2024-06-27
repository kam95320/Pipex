/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:28:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/01 17:56:39 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parent(t_data *data)
{
	int	i;

	i = -1;
	close_pipes(data);
	while (++i < data->cmd.n)
		waitpid(data->pid[i], &data->status, 0);
	clear_all(data);
	exit(WEXITSTATUS(data->status));
}

void	ft_exec(t_data *data, char **envp, char *cmd)
{
	data->cmd.args = ft_split(cmd, ' ');
	if (!data->cmd.paths)
		print_file_error(data->cmd.args[0], UNEXISTING_FILE, 1);
	data->cmd.c_path = get_c_path(data->cmd.paths, data->cmd.args[0]);
	if (!data->cmd.c_path)
		put_cmd_error(data->cmd.args[0], data);
	if (execve(data->cmd.c_path, data->cmd.args, envp) < 0)
		put_cmd_error(data->cmd.args[0], data);
}

void	redirect(int input, int output, t_data *data)
{
	dup2(input, STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	close_pipes(data);
}

void	child(t_data *data, char **av, char **envp)
{
	data->pid[data->i] = fork();
	if (data->pid[data->i] == -1)
		print_error("fork", EXIT_FAILURE, data);
	if (data->pid[data->i] == 0)
	{
		if (data->i == 0)
			redirect(data->in, data->fd[0][1], data);
		else if (data->i == data->pipes)
			redirect(data->fd[data->i - 1][0], data->out, data);
		else
			redirect(data->fd[data->i - 1][0], data->fd[data->i][1], data);
		if ((data->in_err >= 0 && data->i == 0) || (data->out_err > 0
				&& data->i == data->pipes))
			clear_child(data);
		close_files(data);
		ft_exec(data, envp, av[2 + data->i + data->here_doc]);
	}
}
