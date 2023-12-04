/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:26:24 by tmalless          #+#    #+#             */
/*   Updated: 2023/12/04 19:58:29 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* void	frame_rate(t_data *g)
{
	if (difftime(time(NULL), g->time) == 1)
	{
		printf("%d FPS\n", (int)(g->frame - g->ref_frame));
		g->ref_frame = g->frame;
		g->time = time(NULL);
	}
} */

int	looping(t_data *g)
{
	check_mv(g);
	ray_caster(g);
	draw_map(g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->g_img.img, 0, 0);
	g->frame++;
	return (0);
}
	/* frame_rate(g); */

void	init_hook(t_data *g)
{
	mlx_loop_hook(g->mlx, looping, g);
	mlx_hook(g->mlx_win, 2, 1L << 0, key_hook, g);
	mlx_hook(g->mlx_win, 3, 1L << 1, key_release, g);
	mlx_hook(g->mlx_win, 17, 0L, exit_game, g);
	mlx_loop(g->mlx);
}

void	init_game(t_data *g)
{
	init_p(g);
	init_textures(g);
	init_img(g);
	init_hook(g);
}
