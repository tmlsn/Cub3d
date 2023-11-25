/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:19:01 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/25 19:22:07 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_game(t_data *g, float ra, float dist, int r)
{
	float height;
	float	offset;
	float	fisheye;
	int j;

	fisheye = g->p.a - ra;
	if (fisheye < 0)
		fisheye += 2 * PI;
	dist *= cos(fisheye);
	height = (720 * 32) / dist;
	if (height > 720)
		height = 720;
	offset = (720 / 2) - height / 2;
	if (r < 256)
		j = 256;
	else
		j = 0;
	while (j < offset)
	{
		mlx_pixel_put(g->mlx, g->mlx_win, r, j, g->ceiling_color);
		j++;
	}
	while (j < height + offset)
	{
		mlx_pixel_put(g->mlx, g->mlx_win, r, j, g->r.color);
		j++;
	}
	while (j < 720)
	{
		mlx_pixel_put(g->mlx, g->mlx_win, r, j, g->floor_color);
		j++;
	}
}

void	draw_window(t_data *g, float ra, float dist, int r)
{
	float height;
	float	offset;
	float	fisheye;
	int j;

	fisheye = g->p.a - ra;
	if (fisheye < 0)
		fisheye += 2 * PI;
	dist *= cos(fisheye);
	height = (720 * 32) / dist;
	if (height > 720)
		height = 720;
	offset = (720 / 2) - height / 2;
	if (r < 256)
		j = 256;
	else
		j = offset;
	while (j < height + offset)
	{
		if ((j >= offset && j < offset + 10) || (j >= offset + height - 10 && j < offset + height) /* || r % 32 < 6 || r % 32 > 27 */)
			mlx_pixel_put(g->mlx, g->mlx_win, r, j, 0);
		else if (j % 2 == 0 && r % 2 == 0)
			mlx_pixel_put(g->mlx, g->mlx_win, r, j, 000150255);
		j++;
	}
}