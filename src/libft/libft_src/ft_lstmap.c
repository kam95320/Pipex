/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:45:39 by lkhalifa          #+#    #+#             */
/*   Updated: 2023/12/08 18:38:49 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*n_stack;
	void	*elem;

	if (!lst || !f || !del)
		return (0);
	n_list = 0;
	while (lst)
	{
		elem = f(lst->content);
		n_stack = ft_lstnew(elem);
		if (!n_stack)
		{
			del(elem);
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&n_list, n_stack);
		lst = lst->next;
	}
	return (n_list);
}
