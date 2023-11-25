/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_lowercase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:03:38 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/25 16:40:53 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}

int	ft_line_lowercase(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isupper(line[i]))
			line[i] = ft_tolower(line[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
