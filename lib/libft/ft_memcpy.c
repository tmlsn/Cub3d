/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:16:35 by tmalless          #+#    #+#             */
/*   Updated: 2022/11/09 16:58:56 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	cpt;
	char	*d;
	char	*s;

	cpt = 0;
	d = dest;
	s = (char *)src;
	while (cpt < n)
	{
		d[cpt] = s[cpt];
		cpt++;
	}
	return (dest);
}
