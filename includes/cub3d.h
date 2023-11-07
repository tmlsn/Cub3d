/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:10:34 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/07 17:41:22 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "struct.h"
# include "librairies.h"
# include "raycast.h"

// MINILIBX
# include "mlx.h"
# include "mlx_int.h"

# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

# define PI 3.14
# define SIDE 0.785398
# define P2 1.5707963268
# define P3 4.7123889804
# define DR 0.0174533 // 1 degre = DR radians

// MAP
char	**dup_map(char *av);
void	draw_map(t_data *g);

// PLAYER
void	init_p(t_data *g);
void	draw_p(t_data *g);

// HOOKS
int		key_hook(int keycode, t_data *g);
int		key_release(int keycode, t_data *g);

// MOOVES
void	check_mv(t_data *g);
void	look_r(t_data *g);
void	look_l(t_data *g);
int		wall_check(float a, t_data *g);

#endif