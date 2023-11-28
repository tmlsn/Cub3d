/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster_h.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:33:19 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/28 18:05:21 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rch_from_under(float aTan, t_data *g)
{
	g->r.hy = (((int)g->p.y >> 5) << 5) - 0.001;
	g->r.hx = (g->p.y - g->r.hy) * aTan + g->p.x;
	g->r.yo = -32;
	g->r.xo = -g->r.yo * aTan;
}

void	rch_from_above(float aTan, t_data *g)
{
	g->r.hy = (((int)g->p.y >> 5) << 5) + 32;
	g->r.hx = (g->p.y - g->r.hy) * aTan + g->p.x;
	g->r.yo = 32;
	g->r.xo = -g->r.yo * aTan;
}

void	rch_from_side(t_data *g)
{
	g->r.hx = g->p.x;
	g->r.hy = g->p.y;
	g->r.dof = g->map_width;
}

void	find_rch(t_data *g)
{
	while (g->r.dof < g->map_width)
	{
		g->r.mx = (int)(g->r.hx) >> 5;
		g->r.my = (int)(g->r.hy) >> 5;
		if (g->r.my >= 0 && g->r.mx >= 0
			&& g->r.mx < g->map_width && g->r.my < g->map_height
			&& g->map[g->r.my][g->r.mx] && g->map[g->r.my][g->r.mx] == '1')
		{
			g->r.dof = g->map_width;
		}
		else
		{
			g->r.hx += g->r.xo;
			g->r.hy += g->r.yo;
			g->r.dof++;
		}
	}
}

void	ray_casterh(t_data *g, float ra)
{
	g->r.dof = 0;
	if (ra > PI)
		rch_from_under(-1 / (tan(ra)), g);
	if (ra < PI)
		rch_from_above(-1 / (tan(ra)), g);
	if (ra == 0 || ra == PI)
		rch_from_side(g);
	find_rch(g);
}
