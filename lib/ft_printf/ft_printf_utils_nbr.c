/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:26:50 by tmalless          #+#    #+#             */
/*   Updated: 2022/11/28 10:25:46 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handlenbr(va_list ap, int is_signed)
{
	int				n;
	unsigned int	un;

	if (is_signed == 1)
	{
		n = (int) va_arg(ap, int);
		ft_putnbr(n);
		return (ft_nbrsize(n));
	}
	else
	{
		un = (unsigned int) va_arg(ap, unsigned int);
		ft_putunbr(un);
		return (ft_unbrsize(un));
	}
}

void	ft_putnbr(int n)
{
	int	num;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		write(1, "-", 1);
		ft_putnbr(n * -1);
	}
	else if (n < 10)
	{
		num = n + 48;
		write(1, &num, 1);
		return ;
	}
	else
	{
		ft_putnbr(n / 10);
		num = n % 10 + 48;
		write(1, &num, 1);
	}
}

void	ft_putunbr(unsigned int n)
{
	unsigned int	num;

	if (n < 10)
	{
		num = n + 48;
		write(1, &num, 1);
		return ;
	}
	else
	{
		ft_putunbr(n / 10);
		num = n % 10 + 48;
		write(1, &num, 1);
	}
}

int	ft_nbrsize(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		if (n == -2147483648)
			return (11);
		while (n != 0)
		{
			n /= 10;
			i++;
		}
		return (i + 1);
	}
	else
	{
		while (n != 0)
		{
			n /= 10;
			i++;
		}
		return (i);
	}
}

int	ft_unbrsize(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
