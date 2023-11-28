/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:17:23 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/28 18:09:41 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

// RAY CASTING
void	ray_caster(t_data *g);
void	ray_casterh(t_data *g, float ra);
void	ray_casterv(t_data *g, float ra);
void	pick_v_or_h(t_data *g);
void	win_check(t_data *g, float ra);
void	winv(t_data *g, float ra);
void	winh(t_data *g, float ra);
float	dist(float px, float py, float rx, float ry);

// 3D RENDER
void	draw_game(t_data *g, float ra, float dist, int r);
void	draw_window(t_data *g, float ra, float dist, int r);
void	break_window(t_data *g);
void	pixel_put(t_data *g, int x, int y, int color);

// MINI MAP
int		get_x(t_data *g);
int		get_y(t_data *g);

#endif