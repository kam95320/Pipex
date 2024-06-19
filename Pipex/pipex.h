/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:33:34 by kahoumou          #+#    #+#             */
/*   Updated: 2024/06/03 15:43:26 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	exit_handler(int n_exit);
int		open_file(char *file, int in_or_out);
char	*find_road_for_env(char *var_env, char **env);
char	*get_path(char *cmd, char **env);
void	ft_free_tab(char **tab);
void	exec(char *cmd, char **env);
void	ft_putstr_fd(char *s, int fd);
#endif