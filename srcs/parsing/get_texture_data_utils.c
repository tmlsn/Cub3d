/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_data_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:39:13 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/25 16:47:44 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*remove_quotes(char *str)
{
	int		len;
	int		remove_char;
	char	*str_trim;

	len = ft_strlen(str);
	if (str[len - 1] == ',')
		remove_char = 3;
	else
		remove_char = 2;
	str_trim = ft_calloc(len - remove_char + 1, sizeof(char));
	if (!str_trim)
		return (NULL);
	ft_strncpy(str_trim, &str[1], len - remove_char);
	return (str_trim);
}

int	get_color_value(t_xpm *xpm, char c, int nb_colors)
{
	int	i;

	i = 0;
	while (i < nb_colors)
	{
		if (xpm[i].character == c)
			return (xpm[i].value);
		i++;
	}
	return (0);
}

int	get_value_of_rgb(char *line)
{
	int	i;
	int	value;
	int	rgb[3];

	value = 0;
	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	rgb[0] = ft_atoi(&line[i]);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	rgb[1] = ft_atoi(&line[i]);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	rgb[2] = ft_atoi(&line[i]);
	value = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
	return (value);
}

int	get_code_of_color_name(char *line)
{
	const char	*colors_name[] = {"black", "white", "red", "green", "blue",
		"yellow", "cyan", "magenta", "gray", "darkgray", "lightgray", "orange",
		"brown", "purple", "pink", "beige", "olive", "navy", "teal",
		"turquoise", "gold", "silver", "indigo", "maroon", "lime", "coral",
		"lavender", "salmon", "plum", "khaki", "orchid", "azure", "slategray"};
	const int	colors_value[] = {0x000000, 0xFFFFFF, 0xFF0000, 0x00FF00,
		0x0000FF, 0xFFFF00, 0x00FFFF, 0xFF00FF, 0x808080, 0x404040, 0xC0C0C0,
		0xFFA500, 0xA52A2A, 0x800080, 0xFFC0CB, 0xF5F5DC, 0x808000, 0x000080,
		0x008080, 0x40E0D0, 0xFFD700, 0xC0C0C0, 0x4B0082, 0x800000, 0x00FF00,
		0xFF7F50, 0xE6E6FA, 0xFA8072, 0xDDA0DD, 0xF0E68C, 0xDA70D6, 0xF0FFFF,
		0x708090};
	int			i;

	i = 0;
	ft_line_lowercase(line);
	while (i < 33)
	{
		if (ft_strncmp(line, colors_name[i], ft_strlen(colors_name[i])) == 0)
			return (colors_value[i]);
		i++;
	}
	return (0);
}

int	get_xpm_value(char *line)
{
	int	value;

	value = 0;
	if (ft_strncmp(line, "#", 1) == 0)
		value = ft_atoi_base(&line[1], "0123456789ABCDEF");
	else if (ft_strncmp(line, "rgb", 3) == 0)
		value = get_value_of_rgb(line);
	else
		value = get_code_of_color_name(line);
	return (value);
}
