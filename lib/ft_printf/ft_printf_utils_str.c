/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:43:54 by tmalless          #+#    #+#             */
/*   Updated: 2022/11/28 10:59:28 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(va_list ap)
{
	char	c;

	c = (char) va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(va_list ap)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *) va_arg(ap, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
