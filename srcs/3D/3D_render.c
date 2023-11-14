/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:19:01 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/14 15:17:07 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_game(t_data *g, float ra, float dist, int r)
{
	float height;
	float	offset;
	int j;

	height = (720 * 32) / dist;
	if (height > 720)
		height = 720;
	offset = (720 / 2) - height / 2;
	j = 0;
	while (j < offset)
	{
		mlx_pixel_put(g->mlx, g->mlx_win, r, j, 0);
		j++;
	}
	while (j < height + offset)
	{
		mlx_pixel_put(g->mlx, g->mlx_win, r, j, g->r.color);
		j++;
	}
	while (j < 720)
	{
		mlx_pixel_put(g->mlx, g->mlx_win, r, j, 0);
		j++;
	}
}