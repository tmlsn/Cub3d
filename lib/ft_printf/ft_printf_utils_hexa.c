/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hexa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:27:17 by tmalless          #+#    #+#             */
/*   Updated: 2022/11/28 10:55:42 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handlehexa(va_list ap, int hexa_type)
{
	unsigned long long	n;
	unsigned int		un;
	char				*base;

	if (hexa_type == 0)
	{	
		un = (unsigned int) va_arg(ap, unsigned int);
		base = "0123456789abcdef";
		ft_puthexa(un, base);
		return (ft_hexasize(un));
	}
	else if (hexa_type == 1)
	{
		un = (unsigned int) va_arg(ap, unsigned int);
		base = "0123456789ABCDEF";
		ft_puthexa(un, base);
		return (ft_hexasize(un));
	}
	else
	{
		n = (unsigned long long) va_arg(ap, unsigned long long);
		return (ft_handleadd(n));
	}
}

int	ft_handleadd(unsigned long long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		ft_puthexa(n, base);
		return (ft_hexasize(n) + 2);
	}
}

void	ft_puthexa(unsigned long long n, char *base)
{
	char	c;

	if (n < 16)
	{
		c = base[n];
		write(1, &c, 1);
		return ;
	}
	else
	{
		c = base[n % 16];
		ft_puthexa(n / 16, base);
		write(1, &c, 1);
	}
}

int	ft_hexasize(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}
