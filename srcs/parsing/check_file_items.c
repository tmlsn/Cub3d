/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_items.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:16:19 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/30 11:38:23 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture(char **direction, char *line, int *valid)
{
	int	start;

	if (*valid == true)
		return (ft_error("Error, duplicate texture\n"));
	start = 2;
	while (line[start] == ' ')
		start++;
	*direction = ft_substr(line, start, ft_strlen(line));
	if (!*direction)
		return (ft_error(ERROR_MALLOC));
	*valid = true;
	return (EXIT_SUCCESS);
}

int	check_line(char *line)
{
	int	digit;
	int	i;

	i = 1;
	digit = 0;
	while (line[i])
	{
		if (ft_isalpha(line[i]))
			return (ft_error("Error, bad syntaxe for the color\n"));
		while (line[i] && (line[i] == ' ' || ft_isdigit(line[i])))
			i++;
		if (line[i] == 0)
		{
			digit++;
			break ;
		}
		if (line[i] == ',' && i++)
			digit++;
		else
			return (ft_error("Error, bad syntaxe for the color\n"));
	}
	if (digit != 3)
		return (ft_error("Error, bad syntaxe for the color\n"));
	return (EXIT_SUCCESS);
}

/*
 * get_color() check if the color is valid and return it in the int color
*/

int	get_color(int *color, char *line, int *valid)
{
	int	i;
	int	color_rgb[3];

	i = 1;
	if (check_line(line))
		return (EXIT_FAILURE);
	color_rgb[0] = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	color_rgb[1] = ft_atoi(&line[++i]);
	while (line[i] != ',')
		i++;
	color_rgb[2] = ft_atoi(&line[++i]);
	i = -1;
	while (++i < 3)
		if (color_rgb[i] < 0 || color_rgb[i] > 255)
			return (ft_error("Error, color is invalid\n"));
	*color = (color_rgb[0] << 16) + (color_rgb[1] << 8) + color_rgb[2];
	*valid = true;
	return (EXIT_SUCCESS);
}

int	check_file_items_is_in_file(t_data *data, char **texture_path,
char **file, int valid[6])
{
	int	i;
	int	status;

	i = -1;
	status = 0;
	while (file[++i])
	{
		if (ft_strncmp(file[i], "NO ", 3) == 0)
			status = get_texture(&texture_path[NO], file[i], &valid[NO]);
		else if (ft_strncmp(file[i], "SO ", 3) == 0)
			status = get_texture(&texture_path[SO], file[i], &valid[SO]);
		else if (ft_strncmp(file[i], "WE ", 3) == 0)
			status = get_texture(&texture_path[WE], file[i], &valid[WE]);
		else if (ft_strncmp(file[i], "EA ", 3) == 0)
			status = get_texture(&texture_path[EA], file[i], &valid[EA]);
		else if (ft_strncmp(file[i], "F ", 2) == 0)
			status = get_color(&data->floor_color, file[i], &valid[F]);
		else if (ft_strncmp(file[i], "C ", 2) == 0)
			status = get_color(&data->ceiling_color, file[i], &valid[C]);
		if (status == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
 * check_file_items() check if all the items are in the file
*/

int	check_file_items(t_data *data, t_parsing *parsing)
{
	int	valid[6];
	int	i;
	int	ok;

	i = 0;
	parsing->texture_path = ft_calloc(4, sizeof(char *));
	if (!parsing->texture_path)
		return (ft_error(ERROR_MALLOC));
	while (i < 6)
		valid[i++] = false;
	if (check_file_items_is_in_file(data, parsing->texture_path, \
		parsing->file_content_split, valid) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	i = -1;
	ok = 0;
	while (++i < 6)
		if (valid[i] == true)
			ok++;
	if (ok != 6)
		return (ft_error("Error, missing items in the file\n"));
	printf("'blabla\n'");
	i = 0;
	while (i < 4)
		if (ft_strcmp(parsing->texture_path[i++], "") == 0)
			return (ft_error("Error, missing items in the file\n"));
	return (EXIT_SUCCESS);
}
