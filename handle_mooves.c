/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mooves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:04:50 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/04 13:04:15 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	mv_fwd(t_data *g)
{
	if (!vanguard(g))
	{
			g->p.x += g->p.dx;
			g->p.y += g->p.dy;
	}
}

void	mv_bwd(t_data *g)
{
	if (!vanguard(g))
	{
			g->p.x -= g->p.dx;
			g->p.y -= g->p.dy;
	}	
}

void	mv_l(t_data *g)
{
	float	tpdx, tpdy;

	tpdx = cos(g->p.al) * 2;
	tpdy = sin(g->p.al) * 2;
	if (!vanguard(g))
	{
		g->p.x += tpdx;
		g->p.y += tpdy;
	}
}

void	mv_r(t_data *g)
{
	float	tpdx, tpdy;

	tpdx = cos(g->p.ar) * 2;
	tpdy = sin(g->p.ar) * 2;
	if (!vanguard(g))
	{
		g->p.x += tpdx;
		g->p.y += tpdy;
	}
}

void	look_r(t_data *g)
{
	g->p.a += 0.1;
	g->p.al += 0.1;
	g->p.ar += 0.1;
	if (g->p.a > 2 * PI)
		g->p.a -= 2 * PI;
	if (g->p.ar > 2 * PI)
		g->p.ar -= 2 * PI;
	if (g->p.al > 2 * PI)
		g->p.al -= 2 * PI;
	g->p.dx = cos(g->p.a) * 2;
	g->p.dy = sin(g->p.a) * 2;
}

void	look_l(t_data *g)
{
	g->p.a -= 0.1;
	g->p.al -= 0.1;
	g->p.ar -= 0.1;
	if (g->p.a < 0)
		g->p.a += 2 * PI;
	if (g->p.al < 0)
		g->p.al += 2 * PI;
	if (g->p.ar < 0)
		g->p.ar += 2 * PI;
	g->p.dx = cos(g->p.a) * 2;
	g->p.dy = sin(g->p.a) * 2;
}

void	check_mv(t_data *g)
{
	if (g->p.lookl)
	{
		look_l(g);
	}
	if (g->p.lookr)
	{
		look_r(g);
	}
	if (g->p.gof)
	{
		mv_fwd(g);
	}
	if (g->p.gob)
	{
		mv_bwd(g);
	}
	if (g->p.gol)
	{
		mv_l(g);
	}
	if (g->p.gor)
	{
		mv_r(g);
	}
}