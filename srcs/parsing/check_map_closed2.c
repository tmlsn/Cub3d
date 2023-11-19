/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:07:00 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/15 14:13:52 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	y_loop(int x, int y, int map_height, int **valide_case)
{
	while (y < map_height)
	{
		if (valide_case[y][x] == true)
			return (ft_error("Error, map not closed\n"));
		y++;
	}
	return (EXIT_SUCCESS);
}

int	x_loop(int x, int y, int map_width, int **valide_case)
{
	while (x < map_width)
	{
		if (valide_case[y][x] == true)
			return (ft_error("Error, map not closed\n"));
		x++;
	}
	return (EXIT_SUCCESS);
}

int	move_in_empty_case(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y_max)
	{
		x = 0;
		while (x < map->x_max)
		{
			if (map->map[y][x] == EMPTY && map->valide_case[y][x] == true)
				return (ft_error("Error, map not closed\n"));
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

/*
 * Check the border of the map, if it's true, the map is not closed
 * Return EXIT_SUCCESS if the map is closed, else return EXIT_FAILURE
*/

int	map_is_valid(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	if (x_loop(x, y, map->x_max, map->valide_case) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	y = map->y_max - 1;
	x = 0;
	if (x_loop(x, y, map->x_max, map->valide_case) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	x = 0;
	y = 0;
	if (y_loop(x, y, map->y_max, map->valide_case) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	x = map->x_max - 1;
	y = 0;
	if (y_loop(x, y, map->y_max, map->valide_case) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (move_in_empty_case(map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
