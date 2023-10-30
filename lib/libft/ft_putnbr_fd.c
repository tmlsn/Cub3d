/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:16:41 by tmalless          #+#    #+#             */
/*   Updated: 2022/11/18 17:37:58 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

static void	handlemin(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		write(fd, "-", 1);
		ft_putnbr_fd(n * -1, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	num;

	num = n;
	if (n < 0)
		handlemin(n, fd);
	else if (n < 10)
	{
		num = n + 48;
		write(fd, &num, 1);
		return ;
	}
	else
	{
		num = n / 10;
		ft_putnbr_fd(num, fd);
		num = n % 10 + 48;
		write(fd, &num, 1);
	}
}
