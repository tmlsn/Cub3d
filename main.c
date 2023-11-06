/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:09:26 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/04 13:16:22 by tmalless         ###   ########.fr       */
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

void	draw_map(t_data *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g->map.map[i])
	{
		while (g->map.map[i][j])
		{
			if (g->map.map[i][j] == '1')
				fill_wall(g, i, j);
			else
				fill_floor(g, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ray_casterv(t_data *g, float ra)
{
	float xo;
	float yo;
	float aTan;
	int dof = 0;
	int mx, my;

	aTan = -(tan(ra));
	//printf("%f\n", tan(ra));
		if (ra > P2 && ra < P3)
		{
			g->r.vx = (((int)g->p.x>>5)<<5) - 0.001;
			g->r.vy = (g->p.x - g->r.vx) * aTan + g->p.y;
			xo = -32;
			yo = -xo * aTan;
		}
		if (ra < P2 || ra > P3)
		{
			g->r.vx = (((int)g->p.x >> 5) << 5) + 32;
			g->r.vy = (g->p.x - g->r.vx) * aTan + g->p.y;
			xo = 32;
			yo = -xo * aTan;
		}
		if (ra == P2 || ra == P3)
		{
			g->r.vx = g->p.x;
			g->r.vy = g->p.y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(g->r.vx) >> 5;
			my = (int)(g->r.vy) >> 5;
			// printf("g->r.vx: %f, g->r.vy: %f\n", g->r.vx, g->r.vy);
			// printf("mx: %d, my: %d\n", mx, my);
			if (my >= 0 && mx >= 0
				&& mx < 8 && my < 8
				&& g->map.map[my][mx] == '1')
			{
				dof = 8;
			}
			else
			{
				g->r.vx+=xo;
				g->r.vy+=yo;
				dof++;
			}
		}
	//mlx_pixel_put(g->mlx, g->mlx_win, g->r.vx, g->r.vy, 255);
}



void init_p(t_data *g)
{
	g->p.a = P3;
	g->p.al = g->p.a - 2 * SIDE;
	g->p.ar = g->p.a + 2 * SIDE;
	g->p.x = 32 * 4;
	g->p.y = 32 * 3;
	g->p.dx = cos(g->p.a) * 2;
	g->p.dy = sin(g->p.a) * 2;
	g->p.gob = 0;
	g->p.gof = 0;
	g->p.gor = 0;
	g->p.gol = 0;
	g->p.lookl = 0;
	g->p.lookr = 0;
}

void	ray_casterh(t_data *g, float ra)
{
	float xo;
	float yo;
	float aTan;
	int dof = 0;
	int mx, my;

	aTan = -1/(tan(ra));
	//printf("%f\n", tan(ra));
		if (ra > PI)
		{
			g->r.hy = (((int)g->p.y>>5)<<5) - 0.001;
			g->r.hx = (g->p.y - g->r.hy) * aTan + g->p.x;
			yo = -32;
			xo= -yo * aTan;
		}
		if (ra < PI)
		{
			g->r.hy = (((int)g->p.y>>5)<<5) + 32;
			g->r.hx = (g->p.y - g->r.hy) * aTan + g->p.x;
			yo = 32;
			xo= -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			g->r.hx = g->p.x;
			g->r.hy = g->p.y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(g->r.hx) >> 5;
			my = (int)(g->r.hy) >> 5;
/* 			printf("g->r.hx: %f, g->r.hy: %f\n", g->r.hx, g->r.hy);
			printf("mx: %d, my: %d\n", mx, my); */
			if (my >= 0 && mx >= 0
				&& mx < 8 && my < 8
				&& g->map.map[my][mx] == '1')
			{
				dof = 8;
			}
			else
			{
				g->r.hx += xo;
				g->r.hy += yo;
				dof++;
			}
		}
	//mlx_pixel_put(g->mlx, g->mlx_win, g->r.hx, g->r.hy, 255);
}

float	dist(float px, float py, float rx, float ry, float ra)
{
	return (sqrt((ry - py) * (ry - py) + (rx - px) * (rx - px)));
}

void	pick_v_or_h(t_data *g)
{
	if (dist(g->p.x, g->p.y, g->r.hx, g->r.hy, g->p.a) > dist(g->p.x, g->p.y, g->r.vx, g->r.vy, g->p.a))
	{
		g->r.rx = g->r.vx;
		g->r.ry = g->r.vy;
	}
	else
	{
		g->r.rx = g->r.hx;
		g->r.ry = g->r.hy;
	}
	mlx_pixel_put(g->mlx, g->mlx_win, g->r.rx, g->r.ry, 255);
}

void	ray_caster(t_data *g)
{
	int	r;
	float 	a;

	r = 0;
	a = g->p.a - 30* DR;
	while (r < 60)
	{
		ray_casterh(g, a),
		ray_casterv(g, a),
		pick_v_or_h(g);
		a += DR;
		r++;
	}
}

void	draw_p(t_data *g)
{
	int	i;
	int	j;

	i = -2;
	j = -2;
	draw_map(g);
	while (i < 3)
	{
		while (j < 3)
		{
			mlx_pixel_put(g->mlx, g->mlx_win, g->p.x + j, g->p.y + i, 255);
			j++;
		}
		j = -2;
		i++;
	}
	/* check_mv(g);
	//mlx_pixel_put(g->mlx, g->mlx_win, g->p.x + (g->p.dx * 10), g->p.y + (g->p.dy * 10), 255);
	ray_caster(g); */
}

int looping(t_data *g)
{
	draw_map(g);
	check_mv(g);
	draw_p(g);
	ray_caster(g);
}

int	side_vanguard(t_data *g, float tpdx, float tpdy)
{
	int	i;
	int	j;

	i = -2;
	j = -2;
	while (i < 3)
	{
		while (j < 3)
		{
			if ((int)((g->p.y + tpdy + i) / 32) < 0 || (int)((g->p.x + tpdx + j) / 32) < 0 || (int)((g->p.y + tpdy + i) / 32) >= 8 || (int)((g->p.x + tpdx + j) / 32) >= 8 || g->map.map[(int)((g->p.y + tpdy + i) / 32)][(int)((g->p.x + tpdx + j) / 32)] == '1')
				return (1);
			/* else if (way && g->map.map[(int)((g->p.y + tpdy + i) / 32)][(int)((g->p.x + tpdx + j) / 32)] == '1')
				return (1); */
			j++;
		}
		j = -2;
		i++;
	}
	return (0);
	/* if (g->map.map[(int)(g->p.y + (sin(0.52)) / 32)][(int)(g->p.x + (cos(g->p.angle + 0.52)) / 32)] != '1' &&
		g->map.map[(int)(g->p.y + (sin(- 0.52)) / 32)][(int)(g->p.x + (cos(g->p.angle - 0.52)) / 32)] != '1')
		return (0);
	else
		return (1); */
}

void	check_way(t_data *g)
{
	if ((g->p.gof && g->p.a > 0 && g->p.a < PI) || (g->p.gob && g->p.a > PI && g->p.a < 2 * PI))
		g->p.up = 1;
	else
		g->p.up = 0;
	if ((g->p.gob && g->p.a > 0 && g->p.a < PI) || (g->p.gof && g->p.a > PI && g->p.a < 2 * PI))
		g->p.down = 1;
	else
		g->p.down = 0;
	if ((g->p.gor && g->p.a > P2 && g->p.a < P3) || (g->p.gob && g->p.a > PI && g->p.a < 2 * PI))
		g->p.up = 1;
	else
		g->p.up = 0;
}

int	vanguard(t_data *g, int way)
{
	int	i;
	int	j;
	
	float a, b, c, d;
	(void) way;
	i = -2;
	j = -2;
	a = 10 * DR;

	while (i < 36)
	{
		if (g->map.map[(int)(((g->p.y + sin(a) * 6) + 1) / 32)][(int)(((g->p.x + cos(a) * 6) + 1) / 32)] == '1')
			return (1);
/* 		else if (g->map.map[(int)(((g->p.y + sin(a) + 1) * 6) / 32)][(int)(((g->p.x + cos(a) + 1) * 6) / 32)] == '1')
			return (1);
		else if (g->map.map[(int)(((g->p.y + sin(a) + 1) * 6) / 32)][(int)(((g->p.x + cos(a) + 1) * 6) / 32)] == '1')
			return (1); */
		i++;
		a += 10 * DR;
	}
	/* b = g->p.a - DR * 60;
	c = g->p.a + DR * 30;
	d = g->p.a + DR * 60;
	if	(a < 0)
		a += 2 * PI;
	if	(b < 0)
		b += 2 * PI;
	if	(c > 2 * PI)
		c -= 2 * PI;
	if	(d > 2 * PI)
		d -= 2 * PI;
	if (g->map.map[(int)((g->p.y + sin(a) * 6) / 32)][(int)((g->p.x + cos(a) * 6) / 32)] == '1')
		return (1);
	if (g->map.map[(int)((g->p.y + sin(b) * 6) / 32)][(int)((g->p.x + cos(b) * 6) / 32)] == '1')
		return (1);
	if (g->map.map[(int)((g->p.y + sin(c) * 6) / 32)][(int)((g->p.x + cos(c) * 6) / 32)] == '1')
		return (1);
	if (g->map.map[(int)((g->p.y + sin(d) * 6) / 32)][(int)((g->p.x + cos(d) * 6) / 32)] == '1')
		return (1); */
	/* while (i < 3)
	{
		while (j < 3)
		{
			if (!way && g->map.map[(int)((g->p.y + g->p.dy + i) / 32)][(int)((g->p.x + g->p.dx + j) / 32)] == '1')
				return (1);
			else if (way && g->map.map[(int)((g->p.y - g->p.dy - i) / 32)][(int)((g->p.x - g->p.dx - j) / 32)] == '1')
				return (1);
			j++;
		}
		j = -2;
		i++;
	} */
	return (0);
	/* if (g->map.map[(int)(g->p.y + (sin(0.52)) / 32)][(int)(g->p.x + (cos(g->p.angle + 0.52)) / 32)] != '1' &&
		g->map.map[(int)(g->p.y + (sin(- 0.52)) / 32)][(int)(g->p.x + (cos(g->p.angle - 0.52)) / 32)] != '1')
		return (0);
	else
		return (1); */
}

int	key_release(int keycode, t_data *g)
{
	if (keycode == 65361)
	{
		g->p.lookl = 0;
	}
	if (keycode == 65363)
	{
		g->p.lookr = 0;
	}
	if (keycode == 115 || keycode == 65364)
	{
		g->p.gob = 0;
	}
	if (keycode == 100)
	{
		g->p.gor = 0;
	}
	if (keycode == 119 || keycode == 65362)
	{
		g->p.gof = 0;
	}
	if (keycode == 97)
	{
		g->p.gol = 0;
	}
	return (0);
} 

int	key_hook(int keycode, t_data *g)
{
	int	i;
	int	j;
	float	tpa, tpdx, tpdy;

	tpa = g->p.a;
	tpdx = g->p.dx;
	tpdy = g->p.dy;
	//printf("x: %f \ny: %f\n", g->p.x, g->p.y);
	if (keycode == 115 || keycode == 65364)
	{
		g->p.gob = 1;
	}
	if (keycode == 65363)
	{
		g->p.lookr = 1;
	}
	if (keycode == 100)
	{
		g->p.gor = 1;
	}
	if (keycode == 119 || keycode == 65362)
	{
		g->p.gof = 1;
	}
	if (keycode == 65361)
	{
		g->p.lookl = 1;
	}
	if (keycode == 97)
	{
		g->p.gol = 1;
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
	print_map(g->map.map);
	mlx_loop_hook(g->mlx, looping, g);
	mlx_hook(g->mlx_win, 2, 1L << 0, key_hook, g);
	mlx_hook(g->mlx_win, 3, 1L << 1, key_release, g);
	mlx_loop(g->mlx);
}
