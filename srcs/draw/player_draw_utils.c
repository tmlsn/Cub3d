/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:08:24 by tmalless          #+#    #+#             */
/*   Updated: 2023/12/04 13:02:50 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_x(t_data *g)
{
	int	x;

	if (g->map_width < 9)
		x = g->p.x;
	else if (g->p.x > 4 * 32 && g->p.x < g->map_width * 32 - 4 * 32)
		x = 4 * 32;
	else if (g->p.x > g->map_width * 32 - 4 * 32)
		x = g->p.x - (g->map_width * 32 - 8 * 32);
	else
		x = g->p.x;
	return (x);
}

int	get_y(t_data *g)
{
	int	y;

	if (g->map_height < 9)
		y = g->p.y;
	else if (g->p.y > 4 * 32 && g->p.y < g->map_height * 32 - 4 * 32)
		y = 4 * 32;
	else if (g->p.y > g->map_height * 32 - 4 * 32)
		y = g->p.y - (g->map_height * 32 - 8 * 32);
	else
		y = g->p.y;
	return (y);
}
