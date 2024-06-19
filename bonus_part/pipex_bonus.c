/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:22:50 by kahoumou          #+#    #+#             */
/*   Updated: 2024/06/18 13:30:49 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pipex_bonus.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

void	do_pipe(char *cmd, char **env)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		close(p_fd[0]);
		dup2(p_fd[1], STDOUT_FILENO);
		close(p_fd[1]);
		exec_cmd(cmd, env);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
		close(p_fd[0]);
		waitpid(pid, NULL, 0);
	}
}

void	add_cmd(t_pipex *pipex, char *cmd)
{
	t_cmd	*new_cmd;
	t_cmd	*temp;

	new_cmd = malloc(sizeof(t_cmd));
	if (!new_cmd)
		exit(EXIT_FAILURE);
	new_cmd->cmd = ft_strdup(cmd);
	if (!new_cmd->cmd)
		exit(EXIT_FAILURE);
	new_cmd->next = NULL;
	if (!pipex->cmds)
		pipex->cmds = new_cmd;
	else
	{
		temp = pipex->cmds;
		while (temp->next)
			temp = temp->next;
		temp->next = new_cmd;
	}
}

void	execute_commands(t_pipex *pipex)
{
	t_cmd	*temp;

	temp = pipex->cmds;
	while (temp->next)
	{
		do_pipe(temp->cmd, pipex->env);
		temp = temp->next;
	}
	dup2(pipex->fd_out, 1);
	exec_cmd(temp->cmd, pipex->env);
}

void	free_cmds(t_cmd *cmds)
{
	t_cmd	*temp;

	while (cmds)
	{
		temp = cmds;
		cmds = cmds->next;
		free(temp->cmd);
		free(temp);
	}
}
