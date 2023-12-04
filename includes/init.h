/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:16:56 by tmalless          #+#    #+#             */
/*   Updated: 2023/12/04 19:33:52 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H

# define INIT_H

# include "cub3d.h"

void	init_textures(t_data *g);
void	init_img(t_data *g);
void	init_game(t_data *g);
void	init_hook(t_data *g);

#endif