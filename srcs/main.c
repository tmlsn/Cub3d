/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:09:26 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/28 18:59:53 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int	looping(t_data *g)
// {
// 	draw_map(g);
// 	check_mv(g);
// 	draw_p(g);
// 	ray_caster(g);
// }
int	looping(t_data *g)
{
	//print_small_map(g);
	check_mv(g);
	ray_caster(g);
	draw_map(g);
	//draw_p(g);
	

	//usleep(10000);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->g_img.img, 0, 0);
	//draw_map(g);
	return (0);
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

char	*get_gname(char *av)
{
	char	*tmp;

	av = ft_strrchr(av, '/') + 1;
	tmp = ft_strchr(av, '.');
	tmp[0] = '\0';
	printf("%s\n", av);
	if (!av)
		return ("X");
	return (av);
}

void	init_img(t_data *g)
{
	/* int g_height;

	g_height = 720; */
	g->g_img.img = mlx_new_image(g->mlx, 1080, 720);
	g->g_img.addr = mlx_get_data_addr(g->g_img.img, &g->g_img.bpp, &g->g_img.ll, &g->g_img.endian);
}

void	init_textures(t_data *g)
{
	int	img_size;

	img_size = 64;
	g->north->img.img = mlx_xpm_file_to_image(g->mlx, g->north->path, &img_size, &img_size);
	if (!g->north->img.img)
		printf("ca marche pas wallah !\n");
	g->north->img.addr = mlx_get_data_addr(g->north->img.img, &g->north->img.bpp, &g->north->img.ll, &g->north->img.endian);
	g->south->img.img = mlx_xpm_file_to_image(g->mlx, g->south->path, &img_size, &img_size);
	g->south->img.addr = mlx_get_data_addr(g->south->img.img, &g->south->img.bpp, &g->south->img.ll, &g->south->img.endian);
	g->east->img.img = mlx_xpm_file_to_image(g->mlx, g->east->path, &img_size, &img_size);
	g->east->img.addr = mlx_get_data_addr(g->east->img.img, &g->east->img.bpp, &g->east->img.ll, &g->east->img.endian);
	g->west->img.img = mlx_xpm_file_to_image(g->mlx, g->west->path, &img_size, &img_size);
	g->west->img.addr = mlx_get_data_addr(g->west->img.img, &g->west->img.bpp, &g->west->img.ll, &g->west->img.endian);
}

int	main(int ac, char **av)
{
	t_data		*g;
	t_player	player;
	t_texture	texture[4];
	// char	*g_name;

	g = ft_calloc(sizeof(t_data), 1);
	ft_bzero(g, sizeof(t_data));
	ft_bzero(&player, sizeof(t_player));
	ft_bzero(&texture, sizeof(t_texture) * 4);
	g->north = &texture[0];
	g->south = &texture[1];
	g->east = &texture[2];
	g->west = &texture[3];
	g->player = &player;
	//int fd = open(av[1], O_RDONLY);
	if (ac != 2)
		return (ft_error(ERROR_ARG));
	if (parsing(g, av[1]) == EXIT_FAILURE)
		return (destroy_data(g), EXIT_FAILURE);
	// g_name = get_gname(av[1]);
	/* if (ac != 2)
		return (0);
	init_map(g, av[1]); */
	g->mlx = mlx_init();
	if (!g->mlx)
		return (printf("zebi\n"));
	g->mlx_win = mlx_new_window(g->mlx, 1080, 720, "g_name");
	
	// g->mlx_win = mlx_new_window(g->mlx, 32 * g->map.width, 32 * g->map.height, "zeubi");
	/* g->map.height = 32 * 8;
	g->map.width = 32 * 8; */
	init_p(g);
	init_textures(g);

	
	//draw_p(g);
	//print_map(g->map.map);
	init_img(g);
	//usleep(10000000);
	mlx_loop_hook(g->mlx, looping, g);
	mlx_hook(g->mlx_win, 2, 1L << 0, key_hook, g);
	mlx_hook(g->mlx_win, 3, 1L << 1, key_release, g);
	mlx_hook(g->mlx_win, 17, 0L, exit_game, g);
	mlx_loop(g->mlx);
	destroy_data(g);
	return (EXIT_SUCCESS);
}
