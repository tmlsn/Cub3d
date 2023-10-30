/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:10:34 by tmalless          #+#    #+#             */
/*   Updated: 2023/10/30 16:52:47 by tmalless         ###   ########.fr       */
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
	double	deltax;
	double	deltay;
	int		gofwd;
	int		gobwd;
	int		goright;
	int		goleft;
	int		lookl;
	int		lookr;
	float angle;

}				t_player;

typedef struct s_map
{
	char	*file;
	char	**map;
	int		height;
	int		width;
}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_player	player;
}				t_data;

char	**dup_map(char *av);

#endif