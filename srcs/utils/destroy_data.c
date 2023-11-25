/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:50:49 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/15 14:55:56 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	destroy_data(t_data *data)
{
	if (data->north && data->north->path)
	{
		ft_free((void **)&(data->north->path));
		ft_free_tabin(data->north->data, data->north->height);
	}
	if (data->south && data->south->path)
	{
		ft_free((void **)&(data->south->path));
		ft_free_tabin(data->south->data, data->south->height);
	}
	if (data->east && data->east->path)
	{
		ft_free((void **)&(data->east->path));
		ft_free_tabin(data->east->data, data->east->height);
	}
	if (data->west && data->west->path)
	{
		ft_free((void **)&(data->west->path));
		ft_free_tabin(data->west->data, data->west->height);
	}
	if (data->map)
		ft_free_tab(data->map);
	ft_bzero(data, sizeof(t_data));
}
