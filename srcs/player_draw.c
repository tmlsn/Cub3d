/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:25:42 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/07 10:42:56 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_p(t_data *g)
{
	int	i;
	int	j;

	i = -2;
	j = -2;
	draw_map(g);
	while (i < 3)
	{
		while (j < 3)
		{
			mlx_pixel_put(g->mlx, g->mlx_win, g->p.x + j, g->p.y + i, 255);
			j++;
		}
		j = -2;
		i++;
	}
	/* check_mv(g);
	//mlx_pixel_put(g->mlx, g->mlx_win, g->p.x + (g->p.dx * 10), g->p.y + (g->p.dy * 10), 255);
	ray_caster(g); */
}