/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:17:23 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/15 16:58:49 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

// RAY CASTING
void	ray_caster(t_data *g);
void	win_check(t_data *g, int r, float ra);

// 3D RENDER
void	draw_game(t_data *g, float ra, float dist, int r);
void	draw_window(t_data *g, float ra, float dist, int r);

#endif