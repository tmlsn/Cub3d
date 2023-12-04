/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:50:02 by tmalless          #+#    #+#             */
/*   Updated: 2023/12/04 22:12:00 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	clear_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	return (0);
}

void	destroy_imgs(t_data *g)
{
	if (g->north->img.img)
		mlx_destroy_image(g->mlx, g->north->img.img);
	if (g->south->img.img)
		mlx_destroy_image(g->mlx, g->south->img.img);
	if (g->east->img.img)
		mlx_destroy_image(g->mlx, g->east->img.img);
	if (g->west->img.img)
		mlx_destroy_image(g->mlx, g->west->img.img);
	if (g->g_img.img)
		mlx_destroy_image(g->mlx, g->g_img.img);
	if (g->mlx)
		mlx_destroy_display(g->mlx);
}

void	free_text(t_data *g)
{
	free(g->north->path);
	free(g->south->path);
	free(g->west->path);
	free(g->east->path);
}

int	exit_game(t_data *g)
{
	mlx_destroy_window(g->mlx, g->mlx_win);
	destroy_imgs(g);
	free(g->mlx);
	clear_map(g->map);
	free_text(g);
	free(g);
	exit(EXIT_SUCCESS);
	return (0);
}
