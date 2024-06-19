/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:24:53 by kahoumou          #+#    #+#             */
/*   Updated: 2024/06/18 13:14:24 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include "pipex_bonus.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_pipex
{
	int				fd_in;
	int				fd_out;
	char			**env;
	t_cmd			*cmds;
	char			*here_doc_tmp;
}					t_pipex;

void				exit_handler(int n_exit);
int					open_file(char *file, int in_or_out);
char				*find_road_for_env(char *var_env, char **env);
void				ft_free_tab(char **tab);
char				*get_next_line(int fd);
void				execute_commands(t_pipex *pipex);
void				add_cmd(t_pipex *pipex, char *cmd);
char				*join_path(char *path, char *cmd);
char				**get_all_paths(char **env);
char				*check_paths(char **allpath, char **s_cmd);
char				*get_path(char *cmd, char **env);
void				handle_here_doc(t_pipex *pipex, int ac, char **av);
void				handle_infile_outfile(t_pipex *pipex, int ac, char **av);
void				process_commands(t_pipex *pipex, int ac, char **av,
						int start_index);
void				free_cmds(t_cmd *cmds);
void				here_doc_init(t_pipex *pipex, char **av);

#endif