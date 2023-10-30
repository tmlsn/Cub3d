# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 17:21:31 by tmalless          #+#    #+#              #
#    Updated: 2023/10/28 20:21:08 by tmalless         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

SRCS = main.c map_create.c

OBJECT = $(SRCS:.c=.o)

CFLAGS = # -Wall -Wextra -Werror

LIB = lib/get_next_line/gnl.a lib/libft/libft.a lib/ft_printf/libftprintf.a mlx_linux/libmlx_Linux.a #mlx_linux/libmlx.a


CC = cc

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(NAME): $(OBJECT)
	cd lib/libft ; make
	cd lib/get_next_line ; make
	cd lib/ft_printf ; make
	$(CC) $(CFLAGS) $(OBJECT) -L./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIB)

clean : 
	cd lib/libft ; make clean
	cd lib/get_next_line ; make clean
	cd lib/ft_printf ; make clean
	rm -f $(OBJECT) $(OBJECTBONUS)

fclean : clean
	rm -f Cub3d
	cd lib/libft ; make fclean
	cd lib/get_next_line ; make fclean
	cd lib/ft_printf ; make fclean

re : fclean all
	cd lib/libft ; make re
	cd lib/get_next_line ; make re
	cd lib/ft_printf ; make re

.PHONY: all clean fclean re