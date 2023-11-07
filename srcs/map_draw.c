/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:05:31 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/07 10:43:05 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fill_wall(t_data *g, int i, int j)
{
	int	k;
	int	l;

	j *= 32;
	i *= 32;
	k = i + 32;
	l = j + 32;
	while (i < k)
	{
		while (j < l)
		{
			if (i % 32 == 0 || j % 32 == 0)
				mlx_pixel_put(g->mlx, g->mlx_win, j, i, 0);
			else
				mlx_pixel_put(g->mlx, g->mlx_win, j, i, 50);
			j++;
		}
		j -= 32;
		i++;
	}
}

void	fill_floor(t_data *g, int i, int j)
{
	int	k;
	int	l;

	j *= 32;
	i *= 32;
	k = i + 32;
	l = j + 32;
	while (i < k)
	{
		while (j < l)
		{
			if (i % 32 == 0 || j % 32 == 0)
				mlx_pixel_put(g->mlx, g->mlx_win, j, i, 0);
			else
				mlx_pixel_put(g->mlx, g->mlx_win, j, i, 90);
			j++;
		}
		j -= 32;
		i++;
	}
}

void	draw_map(t_data *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g->map.map[i])
	{
		while (g->map.map[i][j])
		{
			if (g->map.map[i][j] == '1')
				fill_wall(g, i, j);
			else
				fill_floor(g, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}