/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:15:29 by tmalless          #+#    #+#             */
/*   Updated: 2022/11/18 17:37:13 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*dup;

	dup = *lst;
	while (dup)
	{
		tmp = dup;
		dup = tmp->next;
		del(tmp->content);
		free(tmp);
	}
	free(dup);
	*lst = 0;
}
