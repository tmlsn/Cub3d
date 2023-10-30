/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:05:50 by tmalless          #+#    #+#             */
/*   Updated: 2022/12/16 12:38:49 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	what_to_print(char format, va_list ap, int count)
{
	if (format == 'c')
		return (count + ft_putchar(ap));
	else if (format == 's')
		return (count + ft_putstr(ap));
	else if (format == 'p')
		return (count + ft_handlehexa(ap, 2));
	else if (format == 'd')
		return (count + ft_handlenbr(ap, 1));
	else if (format == 'i')
		return (count + ft_handlenbr(ap, 1));
	else if (format == 'u')
		return (count + ft_handlenbr(ap, 0));
	else if (format == 'x')
		return (count + ft_handlehexa(ap, 0));
	else if (format == 'X')
		return (count + ft_handlehexa(ap, 1));
	else
	{
		write(1, "%", 1);
		return (count + 1);
	}
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	ap;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count = what_to_print(format[i + 1], ap, count);
			i = i + 2;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(ap);
	return (count);
}
