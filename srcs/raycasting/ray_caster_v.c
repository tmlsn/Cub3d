/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster_v.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:32:09 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/28 18:05:41 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rcv_from_left(float aTan, t_data *g)
{
	g->r.vx = (((int)g->p.x >> 5) << 5) - 0.001;
	g->r.vy = (g->p.x - g->r.vx) * aTan + g->p.y;
	g->r.xo = -32;
	g->r.yo = -g->r.xo * aTan;
}

void	rcv_from_right(float aTan, t_data *g)
{
	g->r.vx = (((int)g->p.x >> 5) << 5) + 32;
	g->r.vy = (g->p.x - g->r.vx) * aTan + g->p.y;
	g->r.xo = 32;
	g->r.yo = -g->r.xo * aTan;
}

void	rcv_from_uad(t_data *g)
{
	g->r.vx = g->p.x;
	g->r.vy = g->p.y;
	g->r.dof = g->map_height;
}

void	find_rcv(t_data *g)
{
	while (g->r.dof < g->map_height)
	{
		g->r.mx = (int)(g->r.vx) >> 5;
		g->r.my = (int)(g->r.vy) >> 5;
		if (g->r.my >= 0 && g->r.mx >= 0
			&& g->r.mx < g->map_width && g->r.my < g->map_height
			&& g->map[g->r.my][g->r.mx] && g->map[g->r.my][g->r.mx] == '1')
		{
			g->r.dof = g->map_height;
		}
		else
		{
			g->r.vx += g->r.xo;
			g->r.vy += g->r.yo;
			g->r.dof++;
		}
	}
}

void	ray_casterv(t_data *g, float ra)
{
	g->r.dof = 0;
	if (ra > P2 && ra < P3)
		rcv_from_left(-(tan(ra)), g);
	if (ra < P2 || ra > P3)
		rcv_from_right(-(tan(ra)), g);
	if (ra == P2 || ra == P3)
		rcv_from_uad(g);
	find_rcv(g);
}
