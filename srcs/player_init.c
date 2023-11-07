/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:25:35 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/07 19:01:32 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_p(t_data *g)
{
	g->p.a = PI;
	g->p.al = g->p.a - 2 * SIDE;
	g->p.ar = g->p.a + 2 * SIDE;
	g->p.x = 40;
	g->p.y = 42;
	g->p.dx = cos(g->p.a) * 2;
	g->p.dy = sin(g->p.a) * 2;
	g->p.gob = 0;
	g->p.gof = 0;
	g->p.gor = 0;
	g->p.gol = 0;
	g->p.lookl = 0;
	g->p.lookr = 0;
}