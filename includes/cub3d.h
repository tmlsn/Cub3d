/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:10:34 by tmalless          #+#    #+#             */
/*   Updated: 2023/11/30 10:22:59 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

// MINILIBX
# include "mlx.h"
# include "mlx_int.h"

# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

# include "struct.h"
# include "librairies.h"
# include "raycast.h"
# include "parsing.h"
# include "utils.h"

//ERROR MESSAGE
# define ERROR_ARG "Error, Invalids arguments\n"
# define ERROR_MALLOC "Error, malloc fail\n"
# define ERROR_WINDOW "Error, window size is invalid\n"
# define ERROR_EMPTY "Error, file is empty\n"
# define ERROR_XPM_COLOR "Error, XPM color is invalid\n" 

# define PI 3.14
# define SIDE 0.785398
# define P2 1.5707963268
# define P3 4.7123889804
# define DR 0.0174533 // 1 degre = DR radians

// MAP
void	init_map(t_data *game, char *av);
char	**dup_map(char *av);
void	draw_map(t_data *g);
void	print_small_map(t_data *g);

// PLAYER
void	init_p(t_data *g);
void	draw_p(t_data *g);
void	draw_p_on_map(t_data *g, int i, int j);

// HOOKS
int		key_hook(int keycode, t_data *g);
int		key_release(int keycode, t_data *g);

// MOOVES
void	check_mv(t_data *g);
void	look_r(t_data *g);
void	look_l(t_data *g);
int		wall_check(float a, t_data *g);

// EXIT
int		exit_game(t_data *g);

#endif