/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:55:34 by kahoumou          #+#    #+#             */
/*   Updated: 2024/06/18 13:13:54 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pipex_bonus.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

char	*join_path(char *path, char *cmd)
{
	char	*path_part;
	char	*exec;

	path_part = ft_strjoin(path, "/");
	if (!path_part)
		return (NULL);
	exec = ft_strjoin(path_part, cmd);
	free(path_part);
	return (exec);
}

char	**get_all_paths(char **env)
{
	char	**allpath;

	allpath = ft_split(find_road_for_env("PATH", env), ':');
	return (allpath);
}

char	*check_paths(char **allpath, char **s_cmd)
{
	int		i;
	char	*exec;

	i = -1;
	while (allpath[++i])
	{
		exec = join_path(allpath[i], s_cmd[0]);
		if (!exec)
			continue ;
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(allpath);
			return (exec);
		}
		free(exec);
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	char	**allpath;
	char	**s_cmd;
	char	*exec;

	allpath = get_all_paths(env);
	if (!allpath)
		return (NULL);
	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
	{
		ft_free_tab(allpath);
		return (NULL);
	}
	exec = check_paths(allpath, s_cmd);
	ft_free_tab(s_cmd);
	if (exec)
		return (exec);
	ft_free_tab(allpath);
	return (cmd);
}
