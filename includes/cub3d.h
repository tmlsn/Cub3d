/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:10:34 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/04 13:01:39 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx_linux/mlx.h"

# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

# define PI 3.14
# define SIDE 0.785398
# define P2 1.5707963268
# define P3 4.7123889804
# define DR 0.0174533 // 1 degre = DR radians

typedef struct s_player
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	int		up;
	int		down;
	int		left;
	int		right;
	int		gof;
	int		gob;
	int		gor;
	int		gol;
	int		lookl;
	int		lookr;
	float a;
	float al;
	float ar;

}				t_player;

typedef struct s_map
{
	char	*file;
	char	**map;
	int		height;
	int		width;
}				t_map;

typedef struct s_ray
{
	int		mx;
	int		my;
	int		xo;
	int		yo;
	float	rx;
	float	ry;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	int		r_n;
	int		r;
}				t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_player	p;
	t_ray		r;

}				t_data;

char	**dup_map(char *av);
void	check_mv(t_data *g);

#endif