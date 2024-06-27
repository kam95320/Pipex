/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:27:40 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/01 17:36:17 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_file_error(char *file, char *str, int file_err)
{
	if (file_err)
		ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(str, 2);
}

void	put_in_error(t_data *data, char *in)
{
	if (data->in_err >= 0)
	{
		if (data->in_err == 0)
			print_file_error(in, BAD_ACCESS, 1);
		else if (data->in_err == 1)
			print_file_error(in, UNEXISTING_FILE, 1);
	}
}

void	put_cmd_error(char *cmd, t_data *data)
{
	print_file_error(cmd, INVALID_COMMAND, 0);
	clear_tab(data->cmd.args);
	clear_all(data);
	if (errno == EACCES)
		exit(126);
	exit(127);
}

void	print_error(char *msg, int exit_code, t_data *data)
{
	perror(msg);
	if (data)
		clear_all(data);
	exit(exit_code);
}

void	check_error(char *file, int n, t_data *data)
{
	if (n == 0)
	{
		if (errno == EACCES)
			data->in_err = 0;
		else if (errno == ENOENT)
			data->in_err = 1;
	}
	else if (errno == ENOENT)
		print_file_error(file, UNEXISTING_FILE, 1);
	else if (errno == EACCES)
		print_file_error(file, BAD_ACCESS, 1);
}
