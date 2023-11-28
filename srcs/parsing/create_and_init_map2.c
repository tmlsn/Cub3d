/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_init_map2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:56:51 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/28 11:58:35 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_bigest_line(char **file_content)
{
	int	i;
	int	j;
	int	bigest;

	i = 0;
	bigest = 0;
	while (file_content[i] && file_content[i][0] == '\0')
		i++;
	while (file_content[i])
	{
		j = 0;
		while (file_content[i][j])
			j++;
		if (j > bigest)
			bigest = j;
		i++;
	}
	return (bigest);
}

char	*create_line(char *line, int bigest_line)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_calloc(sizeof(char), bigest_line + 1);
	while (line[i])
	{
		ret[i] = line[i];
		i++;
	}
	while (i < bigest_line)
	{
		ret[i] = ' ';
		i++;
	}
	return (ret);
}
