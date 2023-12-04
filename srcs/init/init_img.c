/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:53:46 by tmalless          #+#    #+#             */
/*   Updated: 2023/12/04 19:58:08 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_img(t_data *g)
{
	g->g_img.img = mlx_new_image(g->mlx, 1080, 720);
	if (!g->g_img.img)
		exit_game(g);
	g->g_img.addr = mlx_get_data_addr(g->g_img.img,
			&g->g_img.bpp, &g->g_img.ll, &g->g_img.endian);
	if (g->map_height > g->map_width)
		g->r.dof_max = g->map_height;
	else
		g->r.dof_max = g->map_width;
	g->frame = 0;
}
	//g->time = time(NULL);

void	init_textures2(t_data *g, int img_size)
{
	g->west->img.img = mlx_xpm_file_to_image(g->mlx,
			g->west->path, &img_size, &img_size);
	if (!g->west->img.img)
		exit_game(g);
	g->west->img.addr = mlx_get_data_addr(g->west->img.img,
			&g->west->img.bpp, &g->west->img.ll, &g->west->img.endian);
}

void	init_textures(t_data *g)
{
	int	img_size;

	img_size = 64;
	g->north->img.img = mlx_xpm_file_to_image(g->mlx,
			g->north->path, &img_size, &img_size);
	if (!g->north->img.img)
		exit_game(g);
	g->north->img.addr = mlx_get_data_addr(g->north->img.img,
			&g->north->img.bpp, &g->north->img.ll, &g->north->img.endian);
	g->south->img.img = mlx_xpm_file_to_image(g->mlx,
			g->south->path, &img_size, &img_size);
	if (!g->south->img.img)
		exit_game(g);
	g->south->img.addr = mlx_get_data_addr(g->south->img.img,
			&g->south->img.bpp, &g->south->img.ll, &g->south->img.endian);
	g->east->img.img = mlx_xpm_file_to_image(g->mlx,
			g->east->path, &img_size, &img_size);
	if (!g->east->img.img)
		exit_game(g);
	g->east->img.addr = mlx_get_data_addr(g->east->img.img,
			&g->east->img.bpp, &g->east->img.ll, &g->east->img.endian);
	init_textures2(g, img_size);
}
