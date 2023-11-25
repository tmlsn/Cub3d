/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:25:42 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/25 19:08:52 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_sense(t_data *g)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		mlx_pixel_put(g->mlx, g->mlx_win, g->p.x + cos(g->p.a) * i, g->p.y + sin(g->p.a) * i, 100255000);
		i++;
	}
}

void	draw_p(t_data *g)
{
	int	i;
	int	j;

	i = -2;
	j = -2;
	//draw_map(g);
	print_small_map(g);
	while (i < 3)
	{
		while (j < 3)
		{
			mlx_pixel_put(g->mlx, g->mlx_win, g->p.x + j, g->p.y + i, 100255000);
			j++;
		}
		j = -2;
		i++;
	}
	draw_sense(g);
	/*  check_mv(g);
	//mlx_pixel_put(g->mlx, g->mlx_win, g->p.x + (g->p.dx * 10), g->p.y + (g->p.dy * 10), 255);
	ray_caster(g);  */
}

int	get_x(t_data *g)
{
	int	x;

	if (g->p.x > 4 * 32 && g->p.x < g->map_width * 32 - 5 * 32)
		x = 4 * 32;
	else if (g->p.x > g->map_width * 32 - 5 * 32)
		x = g->p.x - (g->map_width * 32 - 9 * 32);
	else
		x = g->p.x;
	return (x);
}

int	get_y(t_data *g)
{
	int	y;

	if (g->p.y > 4 * 32 && g->p.y < g->map_height * 32 - 5 * 32)
		y = 4 * 32;
	else if (g->p.y > g->map_height * 32 - 5 * 32)
		y = g->p.y - (g->map_height * 32 - 9 * 32);
	else
		y = g->p.y;
	return (y);
}

void	draw_sense_on_map(t_data *g, int x, int y)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		mlx_pixel_put(g->mlx, g->mlx_win, x + cos(g->p.a) * i, y + sin(g->p.a) * i, 100255000);
		i++;
	}
}

void	draw_p_on_map(t_data *g)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -2;
	j = -2;
	x = get_x(g);
	y = get_y(g);
	printf("x : %d\n", x);
	printf("y : %d\n", y);
	draw_map(g);
	while (i < 3)
	{
		while (j < 3)
		{
			mlx_pixel_put(g->mlx, g->mlx_win, x + 15 + j, y + 15 + i, 255);
			j++;
		}
		j = -2;
		i++;
	}
	draw_sense_on_map(g, x + 15, y + 15);
	/* check_mv(g);
	//mlx_pixel_put(g->mlx, g->mlx_win, g->p.x + (g->p.dx * 10), g->p.y + (g->p.dy * 10), 255);
	ray_caster(g); */
}