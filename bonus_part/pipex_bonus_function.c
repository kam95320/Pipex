/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:27:03 by kahoumou          #+#    #+#             */
/*   Updated: 2024/06/18 13:22:43 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pipex_bonus.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	open_file(char *file, int in_or_out)
{
	int	open_fd;

	if (in_or_out == 0)
		open_fd = open(file, O_RDONLY, 0644);
	else if (in_or_out == 1)
		open_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (in_or_out == 2)
		open_fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (open_fd == -1)
	{
		ft_putstr_fd("error opening file\n", 2);
		exit(EXIT_FAILURE);
	}
	return (open_fd);
}

void	exit_handler(int n_exit)
{
	if (n_exit == 1)
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
	exit(EXIT_FAILURE);
}

char	*find_road_for_env(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (sub == NULL)
			return (NULL);
		if (ft_strncmp(sub, name, ft_strlen(name)) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

void	exec_cmd(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		exit(EXIT_FAILURE);
	path = get_path(s_cmd[0], env);
	if (path == NULL)
	{
		ft_free_tab(s_cmd);
		exit(EXIT_FAILURE);
	}
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		if (path != cmd)
			free(path);
		exit(EXIT_FAILURE);
	}
	ft_free_tab(s_cmd);
	if (path != cmd)
		free(path);
}
