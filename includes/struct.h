/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:17:30 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/25 16:52:06 by tmalless         ###   ########.fr       */
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
	float	xo;
	float	yo;
	int		dof;
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


/* typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		ll;
}				t_img;
 */
/* typedef struct s_texture
{
	t_img	text;
	char	*path;
}	 		t_texture;*/	

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_player	p;
	t_ray		r;
	t_win		w;
	/* t_img		m_img;
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east; */
}				t_data;

#endif