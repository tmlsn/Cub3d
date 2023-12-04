/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:25:35 by tmalless          #+#    #+#             */
/*   Updated: 2023/12/04 19:57:46 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_p(t_data *g)
{
	if (g->player->start == 'N')
		g->p.a = P3;
	else if (g->player->start == 'S')
		g->p.a = P2;
	else if (g->player->start == 'W')
		g->p.a = PI;
	else if (g->player->start == 'E')
		g->p.a = 0;
	g->p.al = g->p.a - 2 * SIDE;
	g->p.ar = g->p.a + 2 * SIDE;
	g->p.x = g->player->pos.x * 32;
	g->p.y = g->player->pos.y * 32;
	g->p.gob = 0;
	g->p.gof = 0;
	g->p.gor = 0;
	g->p.gol = 0;
	g->p.lookl = 0;
	g->p.lookr = 0;
	g->p.speed = 2;
	g->p.winbrk = 0;
}
