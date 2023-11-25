/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:15:18 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/25 10:29:38 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_height(char **av)
{
	int		height;

	height = 0;
	while (av[height])
		height++;
	return (height);
}

int	map_width(char **av)
{
	int		width;

	width = 0;
	while (av[0][width])
		width++;
	return (width);
}

/* char	**dup_map(char *av)
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
} */

void	init_map(t_data *game, char *av)
{
	game->m.file = av;
	game->m.height = map_height(game->map) - 1;
	game->m.width = map_width(game->map) - 1;
	game->m.map = game->map;
}