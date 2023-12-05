/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semi_small_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:37:58 by tmalless          #+#    #+#             */
/*   Updated: 2023/12/05 11:51:50 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
			if (!ft_strchr("1KV ", g->map[i][j]))
				fill_floor(g, m, j);
			else if (g->map[i][j] == '1')
				fill_wall(g, m, j);
			else if (g->map[i][j] == 'V' || g->map[i][j] == 'K')
				fill_w(g, m, j, g->map[i][j]);
			j++;
		}
		j = 0;
		i++;
		m++;
	}
	draw_p_on_map(g, -2, -2);
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
			if (!ft_strchr("1KV ", g->map[i][j]))
				fill_floor(g, i, n);
			if (g->map[i][j] == '1')
				fill_wall(g, i, n);
			else if (g->map[i][j] == 'V' || g->map[i][j] == 'K')
				fill_w(g, i, n, g->map[i][j]);
			j++;
			n++;
		}
		j = l - 8;
		n = 0;
		i++;
	}
	draw_p_on_map(g, -2, -2);
}
