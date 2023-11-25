/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:50:49 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/25 17:17:52 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	destroy_data(t_data *data)
{
	if (data->map)
		ft_free_tab(data->map);
	ft_bzero(data, sizeof(t_data));
}
