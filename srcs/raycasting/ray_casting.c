/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:02:48 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/30 09:32:43 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	dist(float px, float py, float rx, float ry)
{
	return (sqrt((ry - py) * (ry - py) + (rx - px) * (rx - px)));
}

void	ray_clean(t_data *g)
{
	g->r.whx = 0;
	g->r.why = 0;
	g->r.wvx = 0;
	g->r.wvy = 0;
	g->r.dist = 0;//9999999827968;
	g->r.dish = 0;
	g->r.disv = 0;
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
