/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:39:01 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/25 17:14:23 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
}

void	break_window(t_data *g)
{
	if (g->map.map[(int)(g->p.y + g->p.dy * 8) / 32]
		[(int)(g->p.x + g->p.dx * 8) / 32] == 'V')
		g->map.map[(int)(g->p.y + g->p.dy * 8) / 32]
		[(int)(g->p.x + g->p.dx * 8) / 32] = '0';
}

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
	g->r.dof = g->map.height;
}

void	find_winv(t_data *g)
{
	while (g->r.dof < g->map.height)
	{
		g->r.mx = (int)(g->r.wvx) >> 5;
		g->r.my = (int)(g->r.wvy) >> 5;
		if (g->r.my >= 0 && g->r.mx >= 0
			&& g->r.mx < g->map.width && g->r.my < g->map.height
			&& g->map.map[g->r.my][g->r.mx] == 'V')
		{
			g->r.isw = 1;
			g->r.dof = g->map.height;
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
	g->r.dof = g->map.width;
}

void	find_winh(t_data *g)
{
	while (g->r.dof < g->map.width)
	{
		g->r.mx = (int)(g->r.whx) >> 5;
		g->r.my = (int)(g->r.why) >> 5;
		if (g->r.my >= 0 && g->r.mx >= 0
			&& g->r.mx < g->map.width && g->r.my < g->map.height
			&& g->map.map[g->r.my][g->r.mx] == 'V')
		{
			g->r.isw = 1;
			g->r.dof = g->map.width;
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

void	win_v_or_h(t_data *g, int r)
{
	g->r.winh = dist(g->p.x, g->p.y, g->r.whx, g->r.why, g->p.a);
	g->r.winv = dist(g->p.x, g->p.y, g->r.wvx, g->r.wvy, g->p.a);
	if (g->r.winh < g->r.winv)
	{
		g->r.wx = g->r.whx;
		g->r.wy = g->r.why;
		g->r.wind = g->r.winh;
	}
	else
	{
		g->r.wx = g->r.wvx;
		g->r.wy = g->r.wvy;
		g->r.wind = g->r.winv;
	}
	g->r.winh = 0;
	g->r.winv = 0;
}

void	win_check(t_data *g, int r, float ra)
{
	winh(g, ra);
	winv(g, ra);
	win_v_or_h(g, r);
}
