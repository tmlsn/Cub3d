/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:25:42 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/30 10:18:13 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_sense(t_data *g)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		pixel_put(g, g->p.y + sin(g->p.a) * i,
			g->p.x + cos(g->p.a) * i, 100255000);
		i++;
	}
}

void	draw_p(t_data *g)
{
	int	i;
	int	j;

	i = -2;
	j = -2;
	while (i < 3)
	{
		while (j < 3)
		{
			pixel_put(g, g->p.y + i, g->p.x + j, 100255000);
			j++;
		}
		j = -2;
		i++;
	}
	draw_sense(g);
}

void	draw_sense_on_map(t_data *g, int x, int y)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		pixel_put(g, y + sin(g->p.a) * i, x + cos(g->p.a) * i, 100255000);
		i++;
	}
}

void	draw_p_on_map(t_data *g, int i, int j)
{
	int	k;
	int	l;
	int	x;
	int	y;

	k = 0;
	l = 0;
	x = get_x(g);
	y = get_y(g);
	if (g->map[y / 32][(x + 15) / 32] == 0)
		k = 15;
	if (g->map[(y + 15) / 32][x / 32] == 0)
		l = 15;
	while (i < 3)
	{
		while (j < 3)
		{
			pixel_put(g, y + l + i, x + k + j, 100255000);
			j++;
		}
		j = -2;
		i++;
	}
	draw_sense_on_map(g, x + k, y + l);
}
