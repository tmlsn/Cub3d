/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:39:01 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/15 17:46:57 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	winv(t_data *g, float ra)
{
	float xo;
	float yo;
	float aTan;
	int dof = 0;
	int mx, my;

	aTan = -(tan(ra));
	//printf("%f\n", tan(ra));
		if (ra > P2 && ra < P3)
		{
			g->r.wvx = (((int)g->p.x>>5)<<5) - 0.001;
			g->r.wvy = (g->p.x - g->r.wvx) * aTan + g->p.y;
			xo = -32;
			yo = -xo * aTan;
		}
		if (ra < P2 || ra > P3)
		{
			g->r.wvx = (((int)g->p.x >> 5) << 5) + 32;
			g->r.wvy = (g->p.x - g->r.wvx) * aTan + g->p.y;
			xo = 32;
			yo = -xo * aTan;
		}
		if (ra == P2 || ra == P3)
		{
			g->r.wvx = g->p.x;
			g->r.wvy = g->p.y;
			dof = g->map.height;
		}
		while (dof < g->map.height)
		{
			mx = (int)(g->r.wvx) >> 5;
			my = (int)(g->r.wvy) >> 5;
			// printf("g->r.vx: %f, g->r.vy: %f\n", g->r.vx, g->r.vy);
			// printf("mx: %d, my: %d\n", mx, my);
			if (my >= 0 && mx >= 0
				&& mx < g->map.width && my < g->map.height
				&& g->map.map[my][mx] == 'V')
			{
				g->r.isw = 1;
				dof = g->map.height;
			}
			else
			{
				g->r.wvx+=xo;
				g->r.wvy+=yo;
				dof++;
			}
		}
	//mlx_pixel_put(g->mlx, g->mlx_win, g->r.vx, g->r.vy, 255);
}

void	winh(t_data *g, float ra)
{
	float xo;
	float yo;
	float aTan;
	int dof = 0;
	int mx, my;

	aTan = -1/(tan(ra));
	//printf("%f\n", tan(ra));
		if (ra > PI)
		{
			g->r.why = (((int)g->p.y>>5)<<5) - 0.001;
			g->r.whx = (g->p.y - g->r.why) * aTan + g->p.x;
			yo = -32;
			xo= -yo * aTan;
		}
		if (ra < PI)
		{
			g->r.why = (((int)g->p.y>>5)<<5) + 32;
			g->r.whx = (g->p.y - g->r.why) * aTan + g->p.x;
			yo = 32;
			xo= -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			g->r.whx = g->p.x;
			g->r.why = g->p.y;
			dof = g->map.height;
		}
		while (dof < g->map.width)
		{
			mx = (int)(g->r.whx) >> 5;
			my = (int)(g->r.why) >> 5;
/* 			printf("g->r.hx: %f, g->r.hy: %f\n", g->r.hx, g->r.hy);
			printf("mx: %d, my: %d\n", mx, my); */
			if (my >= 0 && mx >= 0
				&& mx < g->map.width && my < g->map.height
				&& g->map.map[my][mx] == 'V')
			{
				g->r.isw = 1;
				dof = g->map.width;
			}
			else
			{
				g->r.whx += xo;
				g->r.why += yo;
				dof++;
			}
		}
	//mlx_pixel_put(g->mlx, g->mlx_win, g->r.hx, g->r.hy, 255);
}

void	win_v_or_h(t_data *g, int r)
{
	g->r.winh = dist(g->p.x, g->p.y, g->r.whx, g->r.why, g->p.a);
	g->r.winv = dist(g->p.x, g->p.y, g->r.wvx, g->r.wvy, g->p.a);
/* 	if (g->r.winh == g->r.winv || (g->r.winh - g->r.winv < 0.1 && g->r.winh - g->r.winv > -0.1))
	{
		g->r.wx = g->r.whx;
		g->r.wy = g->r.why;
		g->r.wind = g->r.winh;
		//g->r.color = g->r.color;
	} */
	if (g->r.winh > g->r.winv)
	{
		g->r.wx = g->r.wvx;
		g->r.wy = g->r.wvy;
		g->r.wind = g->r.winv;
		/* if (g->p.x > g->r.rx)
			g->r.color = 015020255;
		else
			g->r.color = 000150255; */
	}
	else
	{
		g->r.wx = g->r.whx;
		g->r.wy = g->r.why;
		g->r.wind = g->r.winh;
		/* if (g->p.y > g->r.ry)
			g->r.color = 100255000;
		else
			g->r.color = 800200300; */
	}
	mlx_pixel_put(g->mlx, g->mlx_win, g->r.wx, g->r.wy, 0064213265);
}

void	win_check(t_data *g, int r, float ra)
{
	g->r.isw = 0;
	winh(g, ra);
	winv(g, ra);
	win_v_or_h(g, r);
}