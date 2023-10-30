/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:10:34 by tmalless          #+#    #+#             */
/*   Updated: 2023/10/29 00:24:34 by tmalless         ###   ########.fr       */
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

typedef struct s_player
{
	double	x;
	double	y;
	double	deltax;
	double	deltay;
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