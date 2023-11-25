/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:39:32 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/25 17:16:30 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_file(char **file_content, int *fd)
{
	char	*line;
	char	*tmp;

	line = get_next_line(*fd);
	if (!line)
		return (ft_error(ERROR_EMPTY));
	while (line)
	{
		if (*file_content != NULL)
		{
			tmp = *file_content;
			*file_content = ft_strjoin(*file_content, line);
			if (!file_content)
				return (free(tmp), free(line), ft_error(ERROR_MALLOC));
			ft_free((void **)&tmp);
			free(line);
		}
		else
			*file_content = line;
		line = get_next_line(*fd);
	}
	ft_close(fd);
	return (EXIT_SUCCESS);
}

int	remove_item_from_file_content(char ***file_content)
{
	int	i;

	i = 0;
	while ((*file_content)[i])
	{
		if (ft_strncmp((*file_content)[i], "NO", 2) == 0)
			(*file_content)[i][0] = '\0';
		else if (ft_strncmp((*file_content)[i], "SO", 2) == 0)
			(*file_content)[i][0] = '\0';
		else if (ft_strncmp((*file_content)[i], "WE", 2) == 0)
			(*file_content)[i][0] = '\0';
		else if (ft_strncmp((*file_content)[i], "EA", 2) == 0)
			(*file_content)[i][0] = '\0';
		else if (ft_strncmp((*file_content)[i], "F", 1) == 0)
			(*file_content)[i][0] = '\0';
		else if (ft_strncmp((*file_content)[i], "C", 1) == 0)
			(*file_content)[i][0] = '\0';
		i++;
	}
	return (EXIT_SUCCESS);
}

void	print_data(t_data *data, char *file_name)
{
	int	i;

	printf("\nFILE NAME : ./%s\n", file_name);
	printf("\nNO : %s\n", data->north->path);
	printf("SO : %s\n", data->south->path);
	printf("WE : %s\n", data->west->path);
	printf("EA : %s\n", data->east->path);
	printf("\nFLOOR : 0x%06X rgb(%d, %d, %d)\n", data->floor_color,
		data->floor_color >> 16 & 0xFF, data->floor_color >> 8 & 0xFF,
		data->floor_color & 0xFF);
	printf("CEILING : 0x%06X rgb(%d, %d, %d)\n", data->ceiling_color,
		data->ceiling_color >> 16 & 0xFF, data->ceiling_color >> 8 & 0xFF,
		data->ceiling_color & 0xFF);
	printf("\nMAP :\n");
	i = 0;
	while (data->map[i])
		printf("%s\n", data->map[i++]);
	printf("\nMAP HEIGHT : %d, MAP WIDTH : %d\n",
		data->map_height, data->map_width);
	printf("\nPLAYER POSITION : x = %f, y = %f\n",
		data->player->pos.x, data->player->pos.y);
	printf("PLAYER DIRECTION : x = %f, y = %f\n\n",
		data->player->dir.x, data->player->dir.y);
}

void	destroy_parsing_struct(t_parsing *parsing, int texture)
{
	int	i;

	if (parsing->file_content)
		ft_free((void **)&(parsing->file_content));
	if (parsing->file_content_split)
		ft_free_tab(parsing->file_content_split);
	if (parsing->texture_path)
	{
		if (texture)
		{
			i = 0;
			while (i < 4)
			{
				if (parsing->texture_path[i])
					ft_free((void **)&(parsing->texture_path[i]));
				i++;
			}
		}
		free(parsing->texture_path);
	}
	ft_bzero(parsing, sizeof(t_parsing));
}

int	parsing(t_data *data, char *file_name)
{
	t_parsing	parsing;

	(void)data;
	ft_bzero(&parsing, sizeof(t_parsing));
	parsing.fd = -1;
	if (check_file(file_name, &parsing.fd, CUB))
		return (destroy_parsing_struct(&parsing, true), EXIT_FAILURE);
	if (read_file(&parsing.file_content, &parsing.fd))
		return (destroy_parsing_struct(&parsing, true), EXIT_FAILURE);
	if (parsing.file_content == NULL)
		return (destroy_parsing_struct(&parsing, true), ft_error(ERROR_MALLOC));
	parsing.file_content_split = ft_split_at_endl(parsing.file_content);
	if (!parsing.file_content_split)
		return (destroy_parsing_struct(&parsing, true), ft_error(ERROR_MALLOC));
	if (check_file_items(data, &parsing) == EXIT_FAILURE)
		return (destroy_parsing_struct(&parsing, true), EXIT_FAILURE);
	if (remove_item_from_file_content(&parsing.file_content_split) == \
	EXIT_FAILURE)
		return (destroy_parsing_struct(&parsing, true), EXIT_FAILURE);
	if (create_and_init_map(data, parsing.file_content_split) == EXIT_FAILURE)
		return (destroy_parsing_struct(&parsing, true), EXIT_FAILURE);
	if (check_texture_path(data, &parsing) == EXIT_FAILURE)
		return (destroy_parsing_struct(&parsing, false), EXIT_FAILURE);
	print_data(data, file_name);
	return (destroy_parsing_struct(&parsing, true), EXIT_SUCCESS);
}
