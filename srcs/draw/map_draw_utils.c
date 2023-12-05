/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:25:35 by tmalless          #+#    #+#             */
/*   Updated: 2023/12/05 11:28:03 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_i(t_data *g)
{
	int	i;

	if (g->p.y / 32 < 4)
		i = 0;
	else if ((int)(g->p.y / 32 + 5) > g->map_height)
		i = g->map_height - 8;
	else
		i = g->p.y / 32 - 4;
	return (i);
}

int	get_j(t_data *g)
{
	int	j;

	if (g->p.x / 32 < 4)
		j = 0;
	else if ((int)(g->p.x / 32 + 5) > g->map_width)
		j = g->map_width - 8;
	else
		j = g->p.x / 32 - 4;
	return (j);
}

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
				pixel_put(g, i, j, 0);
			else
				pixel_put(g, i, j, 50);
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
				pixel_put(g, i, j, 0);
			else
				pixel_put(g, i, j, 90);
			j++;
		}
		j -= 32;
		i++;
	}
}

void	fill_w(t_data *g, int i, int j, char c)
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
				pixel_put(g, i, j, 0);
			else if (i % 4 == 0 && j % 4 == 0 && c == 'K')
				pixel_put(g, i, j, 195255825);
			else if (i % 4 == 0 && j % 4 == 0 && c == 'V')
				pixel_put(g, i, j, 000150255);
			else
				pixel_put(g, i, j, 90);
			j++;
		}
		j -= 32;
		i++;
	}
}
