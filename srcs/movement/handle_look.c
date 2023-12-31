/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_look.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:23:04 by tmalless          #+#    #+#             */
/*   Updated: 2023/12/05 11:54:22 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	look_r(t_data *g)
{
	if (g->r.dist < 55)
	{
		g->p.a += 0.1;
		g->p.al += 0.1;
		g->p.ar += 0.1;
	}
	else
	{
		g->p.a += 0.05;
		g->p.al += 0.05;
		g->p.ar += 0.05;
	}
	if (g->p.a > 2 * PI)
		g->p.a -= 2 * PI;
	if (g->p.ar > 2 * PI)
		g->p.ar -= 2 * PI;
	if (g->p.al > 2 * PI)
		g->p.al -= 2 * PI;
}

void	look_l(t_data *g)
{
	if (g->r.dist < 55)
	{
		g->p.a -= 0.1;
		g->p.al -= 0.1;
		g->p.ar -= 0.1;
	}
	else
	{
		g->p.a -= 0.05;
		g->p.al -= 0.05;
		g->p.ar -= 0.05;
	}
	if (g->p.a < 0)
		g->p.a += 2 * PI;
	if (g->p.al < 0)
		g->p.al += 2 * PI;
	if (g->p.ar < 0)
		g->p.ar += 2 * PI;
}
