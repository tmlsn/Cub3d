/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:13:24 by tmalless          #+#    #+#             */
/*   Updated: 2022/11/17 14:57:50 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	size;
	char	*dup;

	i = 0;
	size = ft_strlen(s) + 1;
	dup = (char *) ft_calloc(size, sizeof(char));
	if (!dup)
		return (0);
	while (i < size)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
