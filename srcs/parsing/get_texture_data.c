/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:36:30 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/15 14:40:39 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_xpm_info(t_texture *texture, t_xpm **xpm, int *nb_colors, char *line)
{
	char	*line_trim;
	int		i;

	line_trim = remove_quotes(line);
	if (!line_trim)
		return (ft_error(ERROR_MALLOC));
	i = 0;
	texture->height = ft_atoi(&line_trim[i]);
	while (line_trim[i] && line_trim[i] != ' ')
		i++;
	i++;
	texture->width = ft_atoi(&line_trim[i]);
	while (line_trim[i] && line_trim[i] != ' ')
		i++;
	i++;
	*nb_colors = ft_atoi(&line_trim[i]);
	ft_free((void **)&line_trim);
	*xpm = ft_calloc(*nb_colors + 1, sizeof(t_xpm));
	if (!*xpm)
		return (ft_error(ERROR_MALLOC));
	return (EXIT_SUCCESS);
}

int	get_xpm_color(t_xpm *xpm, char **file_content, int nb_color)
{
	int		i;
	char	*line_trim;

	i = 0;
	line_trim = NULL;
	while (i < nb_color)
	{
		line_trim = remove_quotes(file_content[i]);
		if (!line_trim)
			return (ft_error(ERROR_MALLOC));
		if (ft_strlen(line_trim) != 0)
		{
			xpm[i].character = line_trim[0];
			if (ft_strlen(line_trim) > 4)
				xpm[i].value = get_xpm_value(&line_trim[4]);
			else
				return (ft_error(ERROR_XPM_COLOR));
			ft_free((void **)&line_trim);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	create_texture_data(t_texture *texture, t_xpm *xpm,
	char **file_content, int nb_colors)
{
	int		i;
	int		j;
	char	*line_trim;

	i = 0;
	while (i < texture->height && file_content[i])
	{
		line_trim = remove_quotes(file_content[i]);
		if (!line_trim)
			return (ft_error(ERROR_MALLOC));
		if (ft_strlen(line_trim) != 0)
		{
			j = 0;
			while (j < texture->width && line_trim[j])
			{
				texture->data[i][j] = get_color_value(xpm, line_trim[j],
						nb_colors);
				j++;
			}
			ft_free((void **)&line_trim);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	calloc_texture_data(t_texture *texture)
{
	int	i;

	texture->data = ft_calloc(texture->height, sizeof(int *));
	if (!texture->data)
		return (ft_error(ERROR_MALLOC));
	i = 0;
	while (i < texture->height)
	{
		texture->data[i] = ft_calloc(texture->width, sizeof(int));
		if (!texture->data[i])
			return (ft_free_tabin(texture->data, i), ft_error(ERROR_MALLOC));
		i++;
	}
	return (EXIT_SUCCESS);
}

int	get_texture_info(t_texture *texture, char **files)
{
	const int	nb_line = ft_count_nb_line(files);
	const char	*xpm_strs[] = {"/* columns rows colors chars-per-pixel */",
		"/* pixels */"};
	int			i;
	int			nb_colors;
	t_xpm		*xpm;

	i = 0;
	nb_colors = 0;
	xpm = NULL;
	while (files[i] && ft_strcmp(files[i], xpm_strs[0]))
		i++;
	if (i >= nb_line || i + 1 >= nb_line || i + 2 >= nb_line)
		return (ft_error("Error, invalid texture\n"));
	if (get_xpm_info(texture, &xpm, &nb_colors, files[++i])
		|| get_xpm_color(xpm, &files[++i], nb_colors))
		return (ft_free((void **)&xpm), EXIT_FAILURE);
	while (files[i] && ft_strcmp(files[i], xpm_strs[1]))
		i++;
	if (i >= nb_line || i + 1 >= nb_line)
		return (free(xpm), ft_error("Error, invalid texture\n"));
	return (free(xpm), EXIT_SUCCESS);
}
