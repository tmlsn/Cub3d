/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_init_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:47:29 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/25 16:17:16 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_map(t_data *data, char **file_content)
{
	const int	nb_line = ft_count_nb_line(file_content);
	char		**map;
	int			i;
	int			j;

	i = 0;
	while (file_content[i] && file_content[i][0] == '\0')
		i++;
	if (i < 6)
		return (ft_error("Error, invalid file 3\n"));
	map = ft_calloc(nb_line - i + 1, sizeof(char *));
	if (!map)
		return (ft_error(ERROR_MALLOC));
	j = 0;
	while (file_content[i])
	{
		map[j] = ft_strdup(file_content[i]);
		if (!map[j])
			return (ft_free_tabn(map, j), ft_error(ERROR_MALLOC));
		i++;
		j++;
	}
	data->map = map;
	return (EXIT_SUCCESS);
}

int	check_map_spawn(char **map)
{
	const char	*spawn_char = "NSEW";
	int			spawn;
	int			i;
	int			j;

	spawn = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr(spawn_char, map[i][j]))
				spawn++;
			j++;
		}
		i++;
	}
	if (spawn != 1)
		return (ft_error("Error, invalid spawn\n"));
	return (EXIT_SUCCESS);
}

int	create_map_ints(t_data *data, int ***map_ints)
{
	int	i;

	data->map_width = 0;
	i = 0;
	while (data->map[i])
	{
		if ((int)ft_strlen(data->map[i]) > data->map_width)
			data->map_width = ft_strlen(data->map[i]);
		i++;
	}
	data->map_height = i;
	(*map_ints) = ft_calloc(data->map_height, sizeof(int *));
	if (!(*map_ints))
		return (ft_error(ERROR_MALLOC));
	i = -1;
	while (++i < data->map_height)
	{
		(*map_ints)[i] = ft_calloc(data->map_width, sizeof(int));
		if (!(*map_ints)[i])
			return (ft_free_tabin((*map_ints), i), ft_error(ERROR_MALLOC));
	}
	return (EXIT_SUCCESS);
}

int	init_map_ints(t_data *data, int **map_ints)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == ' ')
				map_ints[y][x] = EMPTY;
			else if (data->map[y][x] == '1')
				map_ints[y][x] = WALL;
			else if (data->map[y][x] == '0')
				map_ints[y][x] = SPACE;
			else if (data->map[y][x] == 'N' || \
				data->map[y][x] == 'S' || \
				data->map[y][x] == 'E' || \
				data->map[y][x] == 'W')
				map_ints[y][x] = SPAWN;
			else
				return (ft_error("Error, invalid char in map\n"));
		}
	}
	return (EXIT_SUCCESS);
}

/*
 * Get the map from the file then check if everything is valid
 * Return EXIT_SUCCESS if everything is valid, else return EXIT_FAILURE
*/

int	create_and_init_map(t_data *data, char **file_content)
{
	int	**map_ints;
	int	i;

	map_ints = NULL;
	if (create_map(data, file_content))
		return (EXIT_FAILURE);
	if (data->map[0] == NULL)
		return (ft_error("Error, invalid file 1\n"));
	i = 0;
	while (data->map[i])
		if (data->map[i++][0] == '\0')
			return (ft_error("Error, invalid file 2\n"));
	if ((ft_strlen(data->map[0]) >= 1 && data->map[1] == NULL) || \
		(data->map[0] != NULL && data->map[1] != NULL && data->map[2] == NULL))
		return (ft_error("Error, map is too short\n"));
	if (check_map_spawn(data->map))
		return (EXIT_FAILURE);
	if (create_map_ints(data, &map_ints))
		return (EXIT_FAILURE);
	if (init_map_ints(data, map_ints))
		return (ft_free_tabin(map_ints, data->map_height), EXIT_FAILURE);
	get_spawn_info(data, map_ints);
	if (check_map_close(data, map_ints))
		return (ft_free_tabin(map_ints, data->map_height), EXIT_FAILURE);
	return (ft_free_tabin(map_ints, data->map_height), EXIT_SUCCESS);
}
