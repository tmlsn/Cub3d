/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:15:18 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/25 18:21:37 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_height(char *av)
{
	int		height;
	int		fd;
	char	*line;

	height = 1;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

int	map_width(char *av)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	width = ft_strlen(line);
	free(line);
	close(fd);
	return (width);
}

char	**dup_map(char *av)
{
	int		i;
	int		fd;
	char	**map;

	i = 0;
	fd = open(av, O_RDONLY);
	map = ft_calloc(map_height(av) + 1, sizeof(char *));
	if (!map)
		return (0);
	while (i < map_height(av) - 1)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			//clear_map(map);
			return (0);
		}
		i++;
	}
	map[i] = 0;
	close(fd);
	return (map);
}

void	init_map(t_data *game, char *av)
{
	game->map_height = map_height(av) - 1;
	game->map_width = map_width(av) - 1;
	game->map = dup_map(av);
}