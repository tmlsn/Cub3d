/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:08:09 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/28 18:42:33 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_release(int keycode, t_data *g)
{
	if (keycode == 65361)
		g->p.lookl = 0;
	if (keycode == 65363)
		g->p.lookr = 0;
	if (keycode == 115 || keycode == 65364)
		g->p.gob = 0;
	if (keycode == 100)
		g->p.gor = 0;
	if (keycode == 119 || keycode == 65362)
		g->p.gof = 0;
	if (keycode == 97)
		g->p.gol = 0;
	if (keycode == 65505 || keycode == 65506)
		g->p.speed = 2;
	if (keycode == 32)
		g->p.winbrk = 0;
	return (0);
}

int	key_hook(int keycode, t_data *g)
{
	if (keycode == 115 || keycode == 65364)
		g->p.gob = 1;
	if (keycode == 65363)
		g->p.lookr = 1;
	if (keycode == 100)
		g->p.gor = 1;
	if (keycode == 119 || keycode == 65362)
		g->p.gof = 1;
	if (keycode == 65361)
		g->p.lookl = 1;
	if (keycode == 97)
		g->p.gol = 1;
	if (keycode == 65505 || keycode == 65506)
		g->p.speed = 6;
	if (keycode == 32)
		g->p.winbrk = 1;
	if (keycode == 65307)
		return (exit_game(g));
	return (0);
}
