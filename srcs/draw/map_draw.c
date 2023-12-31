/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:05:31 by tmalless          #+#    #+#             */
/*   Updated: 2023/12/05 11:38:13 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n");
} */

void	print_small_map(t_data *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g->map[i])
	{
		while (g->map[i][j])
		{
			if (!ft_strchr("1KV ", g->map[i][j]))
				fill_floor(g, i, j);
			else if (g->map[i][j] == '1')
				fill_wall(g, i, j);
			else if (g->map[i][j] == 'V' || g->map[i][j] == 'K')
				fill_w(g, i, j, g->map[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	draw_p(g);
}

void	print_semi_small_map(t_data *g)
{
	if (g->map_height < 9)
		print_low_map(g, 0);
	else if (g->map_width < 9)
		print_thin_map(g, 0);
}

void	print_big_map(t_data *g, int i, int j, int m)
{
	int	k;
	int	l;
	int	n;

	k = i + 8;
	l = j + 8;
	while (g->map[i] && i < k)
	{
		n = 0;
		while (g->map[i][j] && j < l)
		{
			if (!ft_strchr("1KV ", g->map[i][j]))
				fill_floor(g, m, n);
			else if (g->map[i][j] == '1')
				fill_wall(g, m, n);
			else if (g->map[i][j] == 'V' || g->map[i][j] == 'K')
				fill_w(g, m, n, g->map[i][j]);
			j++;
			n++;
		}
		j = l - 8;
		i++;
		m++;
	}
	draw_p_on_map(g, -2, -2);
}

void	draw_map(t_data *g)
{
	if (g->map_height < 9 && g->map_width < 9)
		print_small_map(g);
	else if (g->map_height < 9 || g->map_width < 9)
		print_semi_small_map(g);
	else
		print_big_map(g, get_i(g), get_j(g), 0);
}
