/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:24:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/01 17:38:30 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_access(char *cmd_path)
{
	if (access(cmd_path, X_OK | F_OK) == 0)
		return (1);
	return (0);
}

char	*get_c_path(char **paths, char *cmd)
{
	char	*tmp;
	char	*cmd_path;

	if (ft_count_chars(cmd, '/') > 1)
	{
		if (check_access(cmd))
			return (cmd);
		return (0);
	}
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (check_access(cmd_path))
			return (cmd_path);
		free(cmd_path);
		cmd_path = 0;
		paths++;
	}
	return (0);
}

char	*ft_getenv(char **envp)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		if (ft_strncmp("PATH", envp[i], j) == 0)
			return (ft_strdup(envp[i] + j + 1));
		i++;
	}
	return (NULL);
}

void	get_cmds(int ac, t_data *data, char **envp)
{
	data->cmd.n = ac - 3;
	data->pipes = data->cmd.n - 1;
	data->epath = ft_getenv(envp);
	data->cmd.paths = ft_split(data->epath, ':');
}
