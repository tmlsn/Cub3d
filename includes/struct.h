/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:17:30 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/25 18:03:52 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "librairies.h"

typedef struct s_vector
{
	float		x;
	float		y;
}				t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
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

typedef struct s_texture
{
	char		*path;
	int			width;
	int			height;
	int			**data;
}				t_texture;

typedef struct s_xpm
{
	char	character;
	int		value;
}			t_xpm;

typedef struct s_map
{
	int		**map;
	int		x_max;
	int		y_max;
	int		**valide_case;
}			t_map;

typedef struct s_parsing
{
	int		fd;
	char	*file_content;
	char	**file_content_split;
	char	**texture_path;
}			t_parsing;

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
	t_texture	*north;
	t_texture	*south;
	t_texture	*west;
	t_texture	*east;
	int			floor_color;
	int			ceiling_color;
	char		**map;
	int			map_width;
	int			map_height;
	t_player	*player;
	int			x;
	bool		minimap;
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