/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:36:46 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/28 18:05:49 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pick_v(t_data *g)
{
	g->r.rx = g->r.vx;
	g->r.ry = g->r.vy;
	g->r.dist = g->r.disv;
}

void	pick_h(t_data *g)
{
	g->r.rx = g->r.hx;
	g->r.ry = g->r.hy;
	g->r.dist = g->r.dish;
}

void	pick_v_or_h(t_data *g)
{
	g->r.dish = dist(g->p.x, g->p.y, g->r.hx, g->r.hy);
	g->r.disv = dist(g->p.x, g->p.y, g->r.vx, g->r.vy);
	if (g->r.dish == g->r.disv || (g->r.dish - g->r.disv < 0.1
			&& g->r.dish - g->r.disv > -0.1))
	{
		g->r.rx = g->r.hx;
		g->r.ry = g->r.hy;
		g->r.dist = g->r.dish;
	}
	else if (g->r.dish > g->r.disv)
		pick_v(g);
	else
		pick_h(g);
}
