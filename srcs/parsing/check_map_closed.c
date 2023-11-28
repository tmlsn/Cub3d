/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:39:22 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/26 11:20:00 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Get the spawn position of the player in the map and store them in data
*/
void	get_spawn_info(t_data *data, int **map_ints)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			if (map_ints[i][j] == SPAWN)
			{
				data->player->pos.x = (float)j + 0.5;
				data->player->pos.y = (float)i + 0.5;
				if (data->map[i][j] == 'N')
					data->player->start = 'N';
					//data->player->dir = (t_vector){0, -1};
				else if (data->map[i][j] == 'S')
					data->player->start = 'S';
					//data->player->dir = (t_vector){0, 1};
				else if (data->map[i][j] == 'E')
					data->player->start = 'E';
					//data->player->dir = (t_vector){1, 0};
				else if (data->map[i][j] == 'W')
					data->player->start = 'W';
					//data->player->dir = (t_vector){-1, 0};
			}
		}
	}
}

int	is_valid(t_map *map, int x, int y)
{
	return (x >= 0 && x < map->x_max && y >= 0 && y < map->y_max && \
		map->valide_case[y][x] != true && map->map[y][x] != WALL);
}

void	dfs(t_map *map, int x, int y)
{
	const int	x_inc[] = {0, 1, 0, -1};
	const int	y_inc[] = {-1, 0, 1, 0};
	int			dx;
	int			dy;
	int			i;

	i = 0;
	map->valide_case[y][x] = true;
	while (i < 4)
	{
		dx = x + x_inc[i];
		dy = y + y_inc[i];
		if (is_valid(map, dx, dy))
			dfs(map, dx, dy);
		i++;
	}
}

int	**map_size_dup(int map_width, int map_height)
{
	int	**map_dup;
	int	i;

	map_dup = ft_calloc(map_height, sizeof(int *));
	if (!map_dup)
		return (NULL);
	i = 0;
	while (i < map_height)
	{
		map_dup[i] = ft_calloc(map_width, sizeof(int));
		if (!map_dup[i])
			return (ft_free_tabin(map_dup, i), NULL);
		i++;
	}
	return (map_dup);
}

/*
 * Check if the map is closed, if it's not, priunt an error
 * use DFS algorithm to check if the map is closed and create a new map
 * with true value if we can access to the case and false if we can't
 * return EXIT_SUCCESS if the map is closed,
 * return EXIT_FAILURE if not and print an error message
*/

int	check_map_close(t_data *data, int **map_ints)
{
	t_map		map;
	t_player	*player;
	int			x;
	int			y;

	player = data->player;
	map.map = map_ints;
	map.x_max = data->map_width;
	map.y_max = data->map_height;
	if (player->pos.x == 0 || player->pos.y == 0 || \
		player->pos.x == map.x_max - 1 || player->pos.y == map.y_max - 1)
		return (ft_error("Error, invalid spawn\n"));
	map.valide_case = map_size_dup(map.x_max, map.y_max);
	if (!map.valide_case)
		return (ft_error(ERROR_MALLOC));
	x = player->pos.x;
	y = player->pos.y;
	dfs(&map, x, y);
	if (map_is_valid(&map))
		return (ft_free_tabin(map.valide_case, map.y_max), \
		ft_error("Error, map is not closed\n"));
	return (ft_free_tabin(map.valide_case, map.y_max), EXIT_SUCCESS);
}
