/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:02:48 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/07 11:21:36 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ray_casterv(t_data *g, float ra)
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
			g->r.vx = (((int)g->p.x>>5)<<5) - 0.001;
			g->r.vy = (g->p.x - g->r.vx) * aTan + g->p.y;
			xo = -32;
			yo = -xo * aTan;
		}
		if (ra < P2 || ra > P3)
		{
			g->r.vx = (((int)g->p.x >> 5) << 5) + 32;
			g->r.vy = (g->p.x - g->r.vx) * aTan + g->p.y;
			xo = 32;
			yo = -xo * aTan;
		}
		if (ra == P2 || ra == P3)
		{
			g->r.vx = g->p.x;
			g->r.vy = g->p.y;
			dof = 8;
		}
		while (dof < g->map.height)
		{
			mx = (int)(g->r.vx) >> 5;
			my = (int)(g->r.vy) >> 5;
			// printf("g->r.vx: %f, g->r.vy: %f\n", g->r.vx, g->r.vy);
			// printf("mx: %d, my: %d\n", mx, my);
			if (my >= 0 && mx >= 0
				&& mx < g->map.width && my < g->map.height
				&& g->map.map[my][mx] == '1')
			{
				dof = g->map.height;
			}
			else
			{
				g->r.vx+=xo;
				g->r.vy+=yo;
				dof++;
			}
		}
	//mlx_pixel_put(g->mlx, g->mlx_win, g->r.vx, g->r.vy, 255);
}

void	ray_casterh(t_data *g, float ra)
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
			g->r.hy = (((int)g->p.y>>5)<<5) - 0.001;
			g->r.hx = (g->p.y - g->r.hy) * aTan + g->p.x;
			yo = -32;
			xo= -yo * aTan;
		}
		if (ra < PI)
		{
			g->r.hy = (((int)g->p.y>>5)<<5) + 32;
			g->r.hx = (g->p.y - g->r.hy) * aTan + g->p.x;
			yo = 32;
			xo= -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			g->r.hx = g->p.x;
			g->r.hy = g->p.y;
			dof = 8;
		}
		while (dof < g->map.width)
		{
			mx = (int)(g->r.hx) >> 5;
			my = (int)(g->r.hy) >> 5;
/* 			printf("g->r.hx: %f, g->r.hy: %f\n", g->r.hx, g->r.hy);
			printf("mx: %d, my: %d\n", mx, my); */
			if (my >= 0 && mx >= 0
				&& mx < g->map.width && my < g->map.height
				&& g->map.map[my][mx] == '1')
			{
				dof = g->map.width;
			}
			else
			{
				g->r.hx += xo;
				g->r.hy += yo;
				dof++;
			}
		}
	//mlx_pixel_put(g->mlx, g->mlx_win, g->r.hx, g->r.hy, 255);
}

float	dist(float px, float py, float rx, float ry, float ra)
{
	return (sqrt((ry - py) * (ry - py) + (rx - px) * (rx - px)));
}

void	pick_v_or_h(t_data *g)
{
	if (dist(g->p.x, g->p.y, g->r.hx, g->r.hy, g->p.a) > dist(g->p.x, g->p.y, g->r.vx, g->r.vy, g->p.a))
	{
		g->r.rx = g->r.vx;
		g->r.ry = g->r.vy;
	}
	else
	{
		g->r.rx = g->r.hx;
		g->r.ry = g->r.hy;
	}
	mlx_pixel_put(g->mlx, g->mlx_win, g->r.rx, g->r.ry, 255);
}

void	ray_caster(t_data *g)
{
	int	r;
	float 	a;

	r = 0;
	a = g->p.a - 30 * DR;
	while (r < 60)
	{
		ray_casterh(g, a),
		ray_casterv(g, a),
		pick_v_or_h(g);
		a += DR;
		if (a > 2 * PI)
			a -= 2 * PI;
		r++;
	}
}