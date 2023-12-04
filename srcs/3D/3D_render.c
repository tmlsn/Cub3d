/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:19:01 by tmalless          #+#    #+#             */
/*   Updated: 2023/12/04 20:09:44 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	pixel_put(t_data *g, int x, int y, int color)
{
	char	*dst;

	dst = g->g_img.addr + (x * g->g_img.ll + y * (g->g_img.bpp / 8));
	*(unsigned int *)dst = color;
}

int	pick_colour_from_texture(t_visual text, int height, int wy, t_data *g)
{
	char	*col;
	int		x;
	int		y;
	float	tmp;

	if (g->r.dist == g->r.dish)
		tmp = g->r.rx / 32;
	else
		tmp = g->r.ry / 32;
	tmp -= (int)tmp;
	tmp *= 1000;
	if (text.img == g->north->img.img || text.img == g->west->img.img)
		tmp = 1000 - tmp;
	y = (int) tmp;
	y = 64 * y / 1000;
	if (height == g->r.height)
		x = wy * 64 / height;
	else
		x = (wy + ((g->r.height - height) / 2)) * 64 / g->r.height;
	col = text.addr + (x * text.ll + y * (text.bpp / 8));
	return (*(unsigned int *)col);
}

// USE TEXTURES FOR WALLS

void	pick_colour(t_data *g, int j, int height, int offset)
{
	if (g->r.dish == g->r.dist && g->p.y > g->r.ry)
		g->r.color = pick_colour_from_texture(g->north->img,
				height, j - offset, g);
	else if (g->r.dish == g->r.dist && g->p.y < g->r.ry)
		g->r.color = pick_colour_from_texture(g->south->img,
				height, j - offset, g);
	else if (g->r.disv == g->r.dist && g->p.x > g->r.rx)
		g->r.color = pick_colour_from_texture(g->west->img,
				height, j - offset, g);
	else if (g->r.disv == g->r.dist && g->p.x < g->r.rx)
		g->r.color = pick_colour_from_texture(g->east->img,
				height, j - offset, g);
}

// USE COLORS FOR WALLS

/* void	pick_colour(t_data *g, int j, int height, int offset)
{
	(void)j;
	(void)height;
	(void)offset;
	if (g->r.dish == g->r.dist && g->p.y > g->r.ry)
		g->r.color = 12573489;
	else if (g->r.dish == g->r.dist && g->p.y < g->r.ry)
		g->r.color = 8746394;
	else if (g->r.disv == g->r.dist && g->p.x > g->r.rx)
		g->r.color = 263784399;
	else if (g->r.disv == g->r.dist && g->p.x < g->r.rx)
		g->r.color = 00042736;
} */

void	wall_to_draw(t_data *g, int height, int offset, int r)
{
	int	j;

	j = offset;
	while (j < height + offset)
	{
		if (g->r.dish == g->r.disv || (g->r.dish - g->r.disv < 0.1
				&& g->r.dish - g->r.disv > -0.1))
			pixel_put(g, j, r, g->r.color);
		else
		{
			pick_colour(g, j, height, offset);
			pixel_put(g, j, r, g->r.color);
		}
		j++;
	}
}

void	draw_game(t_data *g, float ra, float dist, int r)
{
	float	height;
	float	offset;
	float	fisheye;
	int		j;

	fisheye = g->p.a - ra;
	if (fisheye < 0)
		fisheye += 2 * PI;
	dist *= cos(fisheye);
	height = (720 * 32) / dist;
	g->r.height = height;
	if (height > 720)
		height = 720;
	offset = (720 / 2) - height / 2;
	j = 0;
	while (j < offset)
	{
		pixel_put(g, j, r, g->ceiling_color);
		j++;
	}
	wall_to_draw(g, height, offset, r);
	j = height + offset - 2;
	while (j++ < 720)
		pixel_put(g, j, r, g->floor_color);
}
