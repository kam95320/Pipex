/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:06:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/01 17:37:51 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac < 5)
		return (ft_putstr_fd("pipex : Invalid number of arguments\n", 2), 0);
	data = init_data(ac, av, envp);
	while (++data.i < data.cmd.n)
		child(&data, av, envp);
	parent(&data);
	return (0);
}
