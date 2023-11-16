/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:17:30 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/16 09:17:33 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	int		speed;
	int		winbrk;
	float	a;
	float	al;
	float	ar;
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
	float	wvx;
	float	wvy;
	float	whx;
	float	why;
	float	wx;
	float	wy;
	float	winv;
	float	winh;
	float	wind;
	int		isw;
	float	disv;
	float	dish;
	float	dist;
	int		color;
	int		r_n;
	int		r;
}				t_ray;

typedef struct s_win
{
	float	wvx;
	float	wvy;
	float	whx;
	float	why;
	float	wx;
	float	wy;
	float	winv;
	float	winh;
	float	wind;
	int		isw;
}				t_win;


typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_player	p;
	t_ray		r;
	t_win		w;
}				t_data;

#endif