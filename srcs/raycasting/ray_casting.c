/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:02:48 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/25 18:19:49 by tmalless         ###   ########.fr       */
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
			&& g->map[g->r.my][g->r.mx] == '1')
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
			&& g->map[g->r.my][g->r.mx] == '1')
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

float	dist(float px, float py, float rx, float ry)
{
	return (sqrt((ry - py) * (ry - py) + (rx - px) * (rx - px)));
}

void	pick_v(t_data *g)
{
	g->r.rx = g->r.vx;
	g->r.ry = g->r.vy;
	g->r.dist = g->r.disv;
	if (g->p.x > g->r.rx)
		g->r.color = 015020255;
	else
		g->r.color = 000150255;
}

void	pick_h(t_data *g)
{
	g->r.rx = g->r.hx;
	g->r.ry = g->r.hy;
	g->r.dist = g->r.dish;
	if (g->p.y > g->r.ry)
		g->r.color = 100255000;
	else
		g->r.color = 800200300;
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
	mlx_pixel_put(g->mlx, g->mlx_win, g->r.rx, g->r.ry, 255);
}

void	ray_clean(t_data *g)
{
	g->r.whx = 0;
	g->r.why = 0;
	g->r.wvx = 0;
	g->r.wvy = 0;
}

void	ray_caster(t_data *g)
{
	int		r;
	float	a;

	r = 0;
	a = g->p.a - (((DR / 18) * 1080) / 2);
	if (a < 0)
		a += 2 * PI;
	while (r < 1080)
	{
		g->r.isw = 0;
		ray_clean(g);
		ray_casterh(g, a),
		ray_casterv(g, a),
		pick_v_or_h(g);
		draw_game(g, a, g->r.dist, r);
		win_check(g, a);
		if (g->r.isw && g->r.wind < g->r.dist)
			draw_window(g, a, g->r.wind, r);
		a += (DR / 18);
		if (a > 2 * PI)
			a -= 2 * PI;
		r++;
	}
}