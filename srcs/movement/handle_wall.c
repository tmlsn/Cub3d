/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:21:46 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/25 10:28:54 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	wall_check(float a, t_data *g)
{
	int	i;
	int	j;

	if (a < 0)
		a += 2 * PI;
	else if (a > 2 * PI)
		a -= 2 * PI;
	i = -2;
	j = -2;
	while (i < 3)
	{
		while (j < 3)
		{
			if (g->m.map[(int)((g->p.y + sin(a) * 3 + i) / 32)][(int)((g->p.x + cos(a) * 3 + j) / 32)] != '0')
				return (1);
			/* else if (way && g->m.map[(int)((g->p.y - g->p.dy - i) / 32)][(int)((g->p.x - g->p.dx - j) / 32)] == '1')
				return (1); */
			j++;
		}
		j = -2;
		i++;
	}
	return (0);
}