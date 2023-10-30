/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:32:44 by tmalless          #+#    #+#             */
/*   Updated: 2022/11/17 18:30:57 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_l;
	t_list	*e;

	new_l = 0;
	while (lst)
	{
		tmp = lst;
		lst = tmp->next;
		e = ft_lstnew(f(tmp->content));
		if (!e)
		{
			ft_lstclear(&new_l, del);
			return (0);
		}
		ft_lstadd_back(&new_l, e);
	}
	return (new_l);
}
