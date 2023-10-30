/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:21:10 by tmalless          #+#    #+#             */
/*   Updated: 2022/11/28 11:01:12 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		what_to_print(char format, va_list ap, int count);
int		ft_putchar(va_list ap);
int		ft_putstr(va_list ap);
int		ft_handlenbr(va_list ap, int is_signed);
void	ft_putnbr(int n);
void	ft_putunbr(unsigned int n);
int		ft_nbrsize(int n);
int		ft_unbrsize(unsigned int n);
int		ft_handlehexa(va_list ap, int hexa_type);
int		ft_handleadd(unsigned long long n);
void	ft_puthexa(unsigned long long n, char *base);
int		ft_hexasize(unsigned long long n);

#endif
