/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:17:23 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/14 14:51:50 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

// RAY CASTING
void	ray_caster(t_data *g);

// 3D RENDER
void	draw_game(t_data *g, float ra, float dist, int r);

#endif