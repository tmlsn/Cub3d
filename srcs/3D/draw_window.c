/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:11:40 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/30 11:55:59 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_window(t_data *g, float ra, float dist, int r)
{
	float	height;
	float	offset;
	float	fisheye;
	int		j;

	fisheye = g->p.a - ra;
	if (fisheye < 0)
		fisheye += 2 * PI;
	dist *= cos(fisheye);
	height = (720 * 32) / dist;
	if (height > 720)
		height = 720;
	offset = (720 / 2) - height / 2;
	j = offset;
	while (j < height + offset)
	{
		if ((j >= offset && j < offset + (height * 0.05))
			|| (j >= offset + height - (height * 0.05) && j < offset + height))
			pixel_put(g, j, r, 0);
		else if (j % 2 == 0 && r % 2 == 0)
			pixel_put(g, j, r, 000150255);
		j++;
	}
}