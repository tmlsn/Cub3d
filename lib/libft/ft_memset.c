/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:51:10 by tmalless          #+#    #+#             */
/*   Updated: 2022/11/09 16:59:10 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	cpt;
	char	*cast;

	cpt = 0;
	cast = s;
	while (cpt < n)
	{
		cast[cpt] = c;
		cpt++;
	}
	return (s);
}
