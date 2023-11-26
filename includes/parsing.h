/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:47:52 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/25 22:44:38 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

enum		e_extention
{
	CUB,
	XPM
};

enum		e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

enum		e_item
{
	NO,
	SO,
	EA,
	WE,
	F,
	C
};

enum		e_map
{
	EMPTY,
	WALL,
	SPACE,
	SPAWN
};

int		check_file(char *file_name, int *fd, int mode);
int		check_map_close(t_data *data, int **map_ints);
int		check_file_items(t_data *data, t_parsing *parsing);
int		check_texture_path(t_data *data, t_parsing *parsing);
int		create_and_init_map(t_data *data, char **file_content);
int		get_xpm_value(char *line);
void	get_spawn_info(t_data *data, int **map_ints);
int		get_color_value(t_xpm *xpm, char c, int nb_colors);
int		get_texture_info(t_texture *texture, char **files);
int		read_file(char **file_content, int *fd);
int		map_is_valid(t_map *map);
char	*remove_quotes(char *str);
int		parsing(t_data *data, char *file_name);

#endif