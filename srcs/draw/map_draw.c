/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:05:31 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/25 19:04:47 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_i(t_data *g)
{
	int	i;
	
	if (g->p.y / 32 < 4)
		i = 0;
	else if ((int)(g->p.y / 32 + 5) > g->map_height)
		i = g->map_height - 9;
	else
		i = g->p.y / 32 - 4;
	printf("i : %d\n", i);
	return (i);
}

int	get_j(t_data *g)
{
	int	j;
	
	if (g->p.x / 32 < 4)
		j = 0;
	else if ((int)(g->p.x / 32 + 5) > g->map_width)
		j = g->map_width - 9;
	else
		j = g->p.x / 32 - 4;
	printf("j : %d\n", j);
	return (j);
}

void	fill_wall(t_data *g, int i, int j)
{
	int	k;
	int	l;

	j *= 32;
	i *= 32;
	k = i + 32;
	l = j + 32;
	while (i < k)
	{
		while (j < l)
		{
			if (i % 32 == 0 || j % 32 == 0)
				mlx_pixel_put(g->mlx, g->mlx_win, j, i, 0);
			else
				mlx_pixel_put(g->mlx, g->mlx_win, j, i, 50);
			j++;
		}
		j -= 32;
		i++;
	}
}

void	fill_floor(t_data *g, int i, int j)
{
	int	k;
	int	l;

	j *= 32;
	i *= 32;
	k = i + 32;
	l = j + 32;
	while (i < k)
	{
		while (j < l)
		{
			if (i % 32 == 0 || j % 32 == 0)
				mlx_pixel_put(g->mlx, g->mlx_win, j, i, 0);
			else
				mlx_pixel_put(g->mlx, g->mlx_win, j, i, 90);
			j++;
		}
		j -= 32;
		i++;
	}
}

void	fill(t_data *g, int i, int j)
{
	int	k;
	int	l;

	j *= 32;
	i *= 32;
	k = i + 32;
	l = j + 32;
	while (i < k)
	{
		while (j < l)
		{
			if (i % 32 == 0 || j % 32 == 0)
				mlx_pixel_put(g->mlx, g->mlx_win, j, i, 0);
			else if ((i % 4 == 0 && j % 4 == 0) || (i % 4 == 1 && j % 4 == 1))
				mlx_pixel_put(g->mlx, g->mlx_win, j, i, 000150255);
			else
				mlx_pixel_put(g->mlx, g->mlx_win, j, i, 90);
			j++;
		}
		j -= 32;
		i++;
	}
}

void	print_small_map(t_data *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g->map[i])
	{
		while (g->map[i][j])
		{
			if (g->map[i][j] == '1')
				fill_wall(g, i, j);
			else if (g->map[i][j] == '0')
				fill_floor(g, i, j);
			else if (g->map[i][j] == 'V')
				fill(g, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	print_thin_map(t_data *g, int m)
{
	int	i;
	int	j;
	int	k;

	i = get_i(g);
	j = 0;
	k = i + 8;
	while (g->map[i] && i < k)
	{
		while (g->map[i][j])
		{
			if (g->map[i][j] == '1')
				fill_wall(g, m, j);
			else if (g->map[i][j] == '0')
				fill_floor(g, m, j);
			j++;
		}
		j = 0;
		i++;
		m++;
	}
}

void	print_low_map(t_data *g, int n)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = get_j(g);
	l = j + 8;
	while (g->map[i])
	{
		while (g->map[i][j] && j < l)
		{
			if (g->map[i][j] == '1')
				fill_wall(g, i, n);
			else if (g->map[i][j] == '0')
				fill_floor(g, i, n);
			j++;
			n++;
		}
		j = l - 8;
		n = 0;
		i++;
	}
}

void	print_semi_small_map(t_data *g)
{
	if (g->map_height < 8)
		print_low_map(g, 0);
	else if (g->map_width < 8)
		print_thin_map(g, 0);
}

void	print_big_map(t_data *g, int k, int l, int m, int n)
{
	int	i;
	int	j;

	i = get_i(g);
	j = get_j(g);
	k = i + 8;
	l = j + 8;
	while (g->map[i] && i < k)
	{
		while (g->map[i][j] && j < l)
		{
			if (g->map[i][j] == '1')
				fill_wall(g, m, n);
			else if (g->map[i][j] == '0')
				fill_floor(g, m, n);
			j++;
			n++;
		}
		j = l - 8;
		n = 0;
		i++;
		m++;
	}
}

void	draw_map(t_data *g)
{
	if (g->map_height < 8 && g->map_width < 8)
		print_small_map(g);
	else if (g->map_height < 8 && g->map_width < 8)
		print_semi_small_map(g);
	else
		print_big_map(g, 0, 0, 0, 0);
}