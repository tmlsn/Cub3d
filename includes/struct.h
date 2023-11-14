/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:17:30 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/14 15:16:11 by tmalless         ###   ########.fr       */
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
	float	dist;
	int		color;
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

#endif