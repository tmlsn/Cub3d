# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 17:21:31 by tmalless          #+#    #+#              #
#    Updated: 2023/11/15 17:08:22 by tmalless         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS_PATH	= ./srcs/
INCS_PATH	= ./includes/

RAYCASTING = raycasting/ray_casting.c raycasting/window_check.c

MOVE = movement/handle_mooves.c movement/handle_wall.c movement/handle_look.c

DRAW = draw/player_draw.c draw/map_draw.c 

UNDEFINED = map_init.c player_init.c key_bindings.c exit.c

3D = 3D/3D_render.c

SRCS = main.c $(RAYCASTING) $(UNDEFINED) $(MOVE) $(DRAW) $(3D)
SRCS := $(addprefix $(SRCS_PATH), $(SRCS))

OBJECT = $(SRCS:.c=.o)

CFLAGS = # -Wall -Wextra -Werror
CFLAGS += -I $(INCS_PATH)

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
	rm -f $(NAME)
	cd lib/libft ; make fclean
	cd lib/get_next_line ; make fclean
	cd lib/ft_printf ; make fclean

re : fclean all
	cd lib/libft ; make re
	cd lib/get_next_line ; make re
	cd lib/ft_printf ; make re

.PHONY: all clean fclean re