/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:46:55 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/30 11:45:37 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	winh_from_above(float aTan, t_data *g)
{
	g->r.why = (((int)g->p.y >> 5) << 5) - 0.001;
	g->r.whx = (g->p.y - g->r.why) * aTan + g->p.x;
	g->r.yo = -32;
	g->r.xo = -g->r.yo * aTan;
}

void	winh_from_under(float aTan, t_data *g)
{
	g->r.why = (((int)g->p.y >> 5) << 5) + 32;
	g->r.whx = (g->p.y - g->r.why) * aTan + g->p.x;
	g->r.yo = 32;
	g->r.xo = -g->r.yo * aTan;
}

void	winh_from_side(t_data *g)
{
	g->r.whx = g->p.x;
	g->r.why = g->p.y;
	g->r.dof = g->r.dof_max;
}

void	find_winh(t_data *g)
{
	while (g->r.dof < g->r.dof_max)
	{
		g->r.mx = (int)(g->r.whx) >> 5;
		g->r.my = (int)(g->r.why) >> 5;
		if (g->r.my >= 0 && g->r.mx >= 0
			&& g->r.mx < g->map_width && g->r.my < g->map_height
			&& g->map[g->r.my][g->r.mx] == 'V')
		{
			g->r.isw = 1;
			g->r.dof = g->r.dof_max;
		}
		else
		{
			g->r.whx += g->r.xo;
			g->r.why += g->r.yo;
			g->r.dof++;
		}
	}
}

void	winh(t_data *g, float ra)
{
	g->r.dof = 0;
	if (ra > PI)
		winh_from_above(-1 / (tan(ra)), g);
	if (ra < PI)
		winh_from_under(-1 / (tan(ra)), g);
	if (ra == 0 || ra == PI)
		winh_from_side(g);
	find_winh(g);
}
