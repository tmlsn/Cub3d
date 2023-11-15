/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:17:30 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/15 13:56:18 by fduzant          ###   ########.fr       */
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
}				t_data;

#endif