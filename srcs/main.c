/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:09:26 by tmalless          #+#    #+#             */
/*   Updated: 2023/12/04 19:53:28 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*get_gname(char *av)
{
	char	*tmp;

	av = ft_strrchr(av, '/') + 1;
	tmp = ft_strchr(av, '.');
	tmp[0] = '\0';
	if (!av)
		return ("X");
	return (av);
}

int	main(int ac, char **av)
{
	t_data		*g;
	char		*g_name;
	t_player	player;
	t_texture	texture[4];

	g = ft_calloc(sizeof(t_data), 1);
	ft_bzero(&player, sizeof(t_player));
	ft_bzero(&texture, sizeof(t_texture) * 4);
	g->north = &texture[0];
	g->south = &texture[1];
	g->east = &texture[2];
	g->west = &texture[3];
	g->player = &player;
	if (ac != 2)
		return (ft_error(ERROR_ARG));
	if (parsing(g, av[1]) == EXIT_FAILURE)
		return (destroy_data(g), EXIT_FAILURE);
	g_name = get_gname(av[1]);
	g->mlx = mlx_init();
	if (!g->mlx)
		return (exit_game(g));
	g->mlx_win = mlx_new_window(g->mlx, 1080, 720, g_name);
	init_game(g);
	return (EXIT_SUCCESS);
}
