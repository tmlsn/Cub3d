/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:39:01 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/28 15:58:17 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
} */

void	break_window(t_data *g)
{
	if (g->map[(int)(g->p.y + g->p.dy * 8) / 32]
		[(int)(g->p.x + g->p.dx * 8) / 32] == 'V')
		g->map[(int)(g->p.y + g->p.dy * 8) / 32]
		[(int)(g->p.x + g->p.dx * 8) / 32] = '0';
}

void	win_v_or_h(t_data *g)
{
	g->r.winh = dist(g->p.x, g->p.y, g->r.whx, g->r.why);
	g->r.winv = dist(g->p.x, g->p.y, g->r.wvx, g->r.wvy);
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

void	win_check(t_data *g, float ra)
{
	winh(g, ra);
	winv(g, ra);
	win_v_or_h(g);
}
