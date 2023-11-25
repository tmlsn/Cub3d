/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:09:26 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/25 10:35:04 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	looping(t_data *g)
{
	print_small_map(g);
	//draw_map(g);
	check_mv(g);
	draw_p(g);
	//draw_p_on_map(g);
	ray_caster(g);
	//draw_map(g);
}
// int	looping(t_data *g)
// {
// 	draw_map(g);
// 	check_mv(g);
// 	draw_p(g);
// 	ray_caster(g);
// }

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

// int	main(int ac, char **av)
// {
// 	t_data *g;
// 	/* t_p *p;
// 	t_map	*map; */

// 	g = ft_calloc(sizeof(t_data), 1);
// 	if (ac != 2)
// 		return (0);
// 	g->mlx = mlx_init();
// 	if (!g->mlx)
// 		return (printf("zebi\n"));
// 	g->mlx_win = mlx_new_window(g->mlx, 32 * 8, 32 * 8, "zeubi");
// 	/* g->map.height = 32 * 8;
// 	g->map.width = 32 * 8; */
// 	g->map.file = av[1];
// 	g->map.map = dup_map(g->map.file);
// 	init_p(g);

// 	//draw_p(g);
// 	//print_map(g->map.map);
// 	mlx_loop_hook(g->mlx, looping, g);
// 	mlx_hook(g->mlx_win, 2, 1L << 0, key_hook, g);
// 	mlx_hook(g->mlx_win, 3, 1L << 1, key_release, g);
// 	mlx_loop(g->mlx);
// }

int	main(int ac, char **av)
{
	t_data		*g;
	/* t_player	player;
	t_texture	texture[4]; */
	g = ft_calloc(sizeof(t_data), 1);
	if (ac != 2)
		return (ft_error(ERROR_ARG));
	if (parsing(g, av[1]) == EXIT_FAILURE)
		return (destroy_data(g), EXIT_FAILURE);
	/* if (ac != 2)
		return (0); */
	init_map(g, av[1]);
	g->mlx = mlx_init();
	if (!g->mlx)
		return (printf("zebi\n"));
	g->mlx_win = mlx_new_window(g->mlx, 1080, 720, "zeubi");
	// g->mlx_win = mlx_new_window(g->mlx, 32 * g->map.width, 32 * g->map.height, "zeubi");
	/* g->map.height = 32 * 8;
	g->map.width = 32 * 8; */
	init_p(g);

	
	//draw_p(g);
	//print_map(g->map.map);
	mlx_loop_hook(g->mlx, looping, g);
	mlx_hook(g->mlx_win, 2, 1L << 0, key_hook, g);
	mlx_hook(g->mlx_win, 3, 1L << 1, key_release, g);
	mlx_loop(g->mlx);
	/* ft_bzero(&data, sizeof(t_data));
	ft_bzero(&player, sizeof(t_player));
	ft_bzero(texture, sizeof(t_texture) * 4);
	data.north = &texture[0];
	data.south = &texture[1];
	data.east = &texture[2];
	data.west = &texture[3];
	data.player = &player; */
	destroy_data(g);
	return (EXIT_SUCCESS);
}
