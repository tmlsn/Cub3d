/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:18:50 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/15 14:45:19 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	if (!str || !base)
		return (-1);
	if (ft_strlen(base) < 2)
		return (-1);
	while (ft_isspace(str[i]))
		i++;
	while (str[i] && ft_strchr(base, str[i]))
	{
		nb = nb * ft_strlen(base) + (ft_strchr(base, str[i]) - base);
		i++;
	}
	return (nb);
}
