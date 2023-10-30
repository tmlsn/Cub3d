/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:09:26 by tmalless          #+#    #+#             */
/*   Updated: 2023/10/30 17:17:30 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"
#include <mlx.h>
#include "./mlx_linux/mlx.h"


/* int mapX = 8, mapY = 8, mapS = 64;
char *map[] =
{
	"11111111",
	"10100001",
	"10000001",
	"10000001",
	"10001101",
	"10010001",
	"10000001",
	"11111111",
};
 */
void	fill_wall(t_data *game, int i, int j)
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
				mlx_pixel_put(game->mlx, game->mlx_win, j, i, 0);
			else
				mlx_pixel_put(game->mlx, game->mlx_win, j, i, 50);
			j++;
		}
		j -= 32;
		i++;
	}
}

void	fill_floor(t_data *game, int i, int j)
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
				mlx_pixel_put(game->mlx, game->mlx_win, j, i, 0);
			else
				mlx_pixel_put(game->mlx, game->mlx_win, j, i, 90);
			j++;
		}
		j -= 32;
		i++;
	}
}

void	draw_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map[i])
	{
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == '1')
				fill_wall(game, i, j);
			else
				fill_floor(game, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ray_casterv(t_data *game, int r)
{
	float rx;
	float ry;
	float ra;
	float xo;
	float yo;
	float aTan;
	int dof = 0;
	int mx, my, mp;

	ra = game->player.angle;
	aTan = -(tan(ra));
	//printf("%f\n", tan(ra));
	while (++r < 1)
	{
		if (ra > P2 && ra < P3)
		{
			rx = (((int)game->player.x>>5)<<5) - 0.001;
			ry = (game->player.x - rx) * aTan + game->player.y;
			xo = -32;
			yo = -xo * aTan;
		}
		if (ra < P2 || ra > P3)
		{
			rx = (((int)game->player.x >> 5) << 5) + 32;
			ry = (game->player.x - rx) * aTan + game->player.y;
			xo = 32;
			yo = -xo * aTan;
		}
		if (ra == P2 || ra == P3)
		{
			rx = game->player.x;
			ry = game->player.y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 5;
			my = (int)(ry) >> 5;
			mp = my * 8 + mx;
			// printf("rx: %f, ry: %f\n", rx, ry);
			// printf("mx: %d, my: %d\n", mx, my);
			if (my >= 0 && mx >= 0
				&& mx < 8 && my < 8
				&& game->map.map[my][mx] == '1')
			{
				dof = 8;
			}
			else
			{
				rx+=xo;
				ry+=yo;
				dof++;
			}
		}
	}
	mlx_pixel_put(game->mlx, game->mlx_win, rx, ry, 255);
}

void init_player(t_data *game)
{
	game->player.x = 32 * 4;
	game->player.y = 32 * 3;
	game->player.deltax = cos(game->player.angle) * 2;
	game->player.deltay = sin(game->player.angle) * 2;
	game->player.gobwd = 0;
	game->player.gofwd = 0;
	game->player.goright = 0;
	game->player.goleft = 0;
	game->player.lookl = 0;
	game->player.lookr = 0;
}

void	ray_casterh(t_data *game, int r)
{
	float rx;
	float ry;
	float ra;
	float xo;
	float yo;
	float aTan;
	int dof = 0;
	int mx, my, mp;

	ra = game->player.angle;
	aTan = -1/(tan(ra));
	//printf("%f\n", tan(ra));
	while (++r < 1)
	{
		if (ra > PI)
		{
			ry = (((int)game->player.y>>5)<<5) - 0.001;
			rx = (game->player.y - ry) * aTan + game->player.x;
			yo = -32;
			xo= -yo * aTan;
		}
		if (ra < PI)
		{
			ry = (((int)game->player.y>>5)<<5) + 32;
			rx = (game->player.y - ry) * aTan + game->player.x;
			yo = 32;
			xo= -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = game->player.x;
			ry = game->player.y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 5;
			my = (int)(ry) >> 5;
			mp = my * 8 + mx;
			printf("rx: %f, ry: %f\n", rx, ry);
			printf("mx: %d, my: %d\n", mx, my);
			if (my >= 0 && mx >= 0
				&& mx < 8 && my < 8
				&& game->map.map[my][mx] == '1')
			{
				dof = 8;
			}
			else
			{
				rx+=xo;
				ry+=yo;
				dof++;
			}
		}
	}
	mlx_pixel_put(game->mlx, game->mlx_win, rx, ry, 255);
}

int	draw_player(t_data *game)
{
	int	i;
	int	j;

	i = -2;
	j = -2;
	draw_map(game);
	while (i < 3)
	{
		while (j < 3)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, game->player.x + j, game->player.y + i, 255);
			j++;
		}
		j = -2;
		i++;
	}
	mlx_pixel_put(game->mlx, game->mlx_win, game->player.x + (game->player.deltax * 10), game->player.y + (game->player.deltay * 10), 255);
	ray_casterh(game, -1);
	ray_casterv(game, -1);
	return (0);
}

int	vanguard(t_data *game, int way)
{
	int	i;
	int	j;

	i = -2;
	j = -2;
	while (i < 3)
	{
		while (j < 3)
		{
			if (!way && game->map.map[(int)((game->player.y + game->player.deltay + i) / 32)][(int)((game->player.x + game->player.deltax + j) / 32)] == '1')
				return (1);
			else if (way && game->map.map[(int)((game->player.y - game->player.deltay - i) / 32)][(int)((game->player.x - game->player.deltax - j) / 32)] == '1')
				return (1);
			j++;
		}
		j = -2;
		i++;
	}
	return (0);
	/* if (game->map.map[(int)(game->player.y + (sin(0.52)) / 32)][(int)(game->player.x + (cos(game->player.angle + 0.52)) / 32)] != '1' &&
		game->map.map[(int)(game->player.y + (sin(- 0.52)) / 32)][(int)(game->player.x + (cos(game->player.angle - 0.52)) / 32)] != '1')
		return (0);
	else
		return (1); */
}

int	key_hook(int keycode, t_data *game)
{
	int	i;
	int	j;
	float	tpa, tpdx, tpdy;

	tpa = game->player.angle;
	tpdx = game->player.deltax;
	tpdy = game->player.deltay;
	printf("x: %f \ny: %f\n", game->player.x, game->player.y);
	if (keycode == 115 || keycode == 65364)
	{
		if (!vanguard(game, 1))
		{
				game->player.x -= game->player.deltax;
				game->player.y -= game->player.deltay;
		}
	}
	if (keycode == 65363)
	{
		game->player.angle += 0.1;
		if (game->player.angle > 2 * PI)
			game->player.angle -= 2 * PI;
		game->player.deltax = cos(game->player.angle) * 2;
		game->player.deltay = sin(game->player.angle) * 2;
	}
	if (keycode == 100)
	{
		tpa += SIDE * 2;
		if (tpa > 2 * PI)
			tpa -= 2 * PI;
		tpdx = cos(tpa) * 2;
		tpdy = sin(tpa) * 2;
		game->player.x += tpdx;
		game->player.y += tpdy;
	}
	if (keycode == 119 || keycode == 65362)
	{
		if (!vanguard(game, 0))
		{
				game->player.x += game->player.deltax;
				game->player.y += game->player.deltay;
		}
	}
	if (keycode == 65361)
	{
		game->player.angle -= 0.1;
		if (game->player.angle < 0)
			game->player.angle += 2 * PI;
		game->player.deltax = cos(game->player.angle) * 2;
		game->player.deltay = sin(game->player.angle) * 2;
	}
	if (keycode == 97)
	{
		tpa -= SIDE * 2;
		if (tpa > 2 * PI)
			tpa -= 2 * PI;
		tpdx = cos(tpa) * 2;
		tpdy = sin(tpa) * 2;
		game->player.x += tpdx;
		game->player.y += tpdy;
	}
	return (0);
}

/* void p_position()
{
	
} */

void	print_map(char **map)
{
	int i = 0;

	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_data *game;
	/* t_player *player;
	t_map	*map; */

	game = ft_calloc(sizeof(t_data), 1);
	if (ac != 2)
		return (0);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (printf("zebi\n"));
	game->mlx_win = mlx_new_window(game->mlx, 32 * 8, 32 * 8, "zeubi");
	/* game->map.height = 32 * 8;
	game->map.width = 32 * 8; */
	game->map.file = av[1];
	game->map.map = dup_map(game->map.file);
	init_player(game);

	
	//draw_player(game);
	print_map(game->map.map);
	mlx_loop_hook(game->mlx, draw_player, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_hook, game);
	mlx_loop(game->mlx);
}
