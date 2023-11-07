/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:09:26 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/07 17:41:32 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	looping(t_data *g)
{
	draw_map(g);
	check_mv(g);
	draw_p(g);
	ray_caster(g);
}

/* void	print_map(char **map)
{
	int i = 0;

	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
} */

int	main(int ac, char **av)
{
	t_data *g;
	/* t_p *p;
	t_map	*map; */

	g = ft_calloc(sizeof(t_data), 1);
	if (ac != 2)
		return (0);
	g->mlx = mlx_init();
	if (!g->mlx)
		return (printf("zebi\n"));
	g->mlx_win = mlx_new_window(g->mlx, 32 * 8, 32 * 8, "zeubi");
	/* g->map.height = 32 * 8;
	g->map.width = 32 * 8; */
	g->map.file = av[1];
	g->map.map = dup_map(g->map.file);
	init_p(g);

	
	//draw_p(g);
	//print_map(g->map.map);
	mlx_loop_hook(g->mlx, looping, g);
	mlx_hook(g->mlx_win, 2, 1L << 0, key_hook, g);
	mlx_hook(g->mlx_win, 3, 1L << 1, key_release, g);
	mlx_loop(g->mlx);
}
