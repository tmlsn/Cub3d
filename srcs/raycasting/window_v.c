/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:47:17 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/28 18:04:35 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	winv_from_left(float aTan, t_data *g)
{
	g->r.wvx = (((int)g->p.x >> 5) << 5) - 0.001;
	g->r.wvy = (g->p.x - g->r.wvx) * aTan + g->p.y;
	g->r.xo = -32;
	g->r.yo = -g->r.xo * aTan;
}

void	winv_from_right(float aTan, t_data *g)
{
	g->r.wvx = (((int)g->p.x >> 5) << 5) + 32;
	g->r.wvy = (g->p.x - g->r.wvx) * aTan + g->p.y;
	g->r.xo = 32;
	g->r.yo = -g->r.xo * aTan;
}

void	winv_from_uad(t_data *g)
{
	g->r.wvx = g->p.x;
	g->r.wvy = g->p.y;
	g->r.dof = g->map_height;
}

void	find_winv(t_data *g)
{
	while (g->r.dof < g->map_height)
	{
		g->r.mx = (int)(g->r.wvx) >> 5;
		g->r.my = (int)(g->r.wvy) >> 5;
		if (g->r.my >= 0 && g->r.mx >= 0
			&& g->r.mx < g->map_width && g->r.my < g->map_height
			&& g->map[g->r.my][g->r.mx] && g->map[g->r.my][g->r.mx] == 'V')
		{
			g->r.isw = 1;
			g->r.dof = g->map_height;
		}
		else
		{
			g->r.wvx += g->r.xo;
			g->r.wvy += g->r.yo;
			g->r.dof++;
		}
	}
}

void	winv(t_data *g, float ra)
{
	g->r.dof = 0;
	if (ra > P2 && ra < P3)
		winv_from_left(-(tan(ra)), g);
	if (ra < P2 || ra > P3)
		winv_from_right(-(tan(ra)), g);
	if (ra == P2 || ra == P3)
		winv_from_uad(g);
	find_winv(g);
}
