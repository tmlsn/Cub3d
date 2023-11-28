/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mooves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:04:50 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/28 12:23:07 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mv_fwd(t_data *g)
{
	g->p.dx = cos(g->p.a) * g->p.speed;
	g->p.dy = sin(g->p.a) * g->p.speed;
	g->p.x += g->p.dx;
	g->p.y += g->p.dy;
}

void	mv_bwd(t_data *g)
{
	g->p.dx = cos(g->p.a) * g->p.speed;
	g->p.dy = sin(g->p.a) * g->p.speed;
	g->p.x -= g->p.dx;
	g->p.y -= g->p.dy;
}

void	mv_l(t_data *g)
{
	g->p.x += cos(g->p.al) * g->p.speed;
	g->p.y += sin(g->p.al) * g->p.speed;
}

void	mv_r(t_data *g)
{
	g->p.x += cos(g->p.ar) * g->p.speed;
	g->p.y += sin(g->p.ar) * g->p.speed;
}

void	check_mv(t_data *g)
{
	if (g->p.lookl)
		look_l(g);
	if (g->p.lookr)
		look_r(g);
	if (g->p.gof && !wall_check(g->p.a, g))
		mv_fwd(g);
	if (g->p.gob && !wall_check(g->p.a - PI, g))
		mv_bwd(g);
	if (g->p.gol && !wall_check(g->p.al, g))
		mv_l(g);
	if (g->p.gor && !wall_check(g->p.ar, g))
		mv_r(g);
	if (g->p.winbrk)
		break_window(g);
}
