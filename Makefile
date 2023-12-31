# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 17:21:31 by tmalless          #+#    #+#              #
#    Updated: 2023/12/05 11:39:35 by tmalless         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS_PATH	= ./srcs/
INCS_PATH	= ./includes/

RAYCASTING = raycasting/ray_casting.c raycasting/window_check.c raycasting/ray_caster_h.c \
			 raycasting/ray_caster_v.c raycasting/pick_ray.c raycasting/window_h.c raycasting/window_v.c

MOVE = movement/handle_mooves.c movement/handle_wall.c movement/handle_look.c movement/key_bindings.c 

DRAW = draw/player_draw.c draw/map_draw.c draw/player_draw_utils.c draw/map_draw_utils.c draw/semi_small_map_utils.c

PARSING = parsing/parsing.c parsing/check_file.c parsing/check_file_items.c parsing/check_map_closed.c \
		  parsing/check_map_closed2.c parsing/check_texture_path.c parsing/create_and_init_map.c \
		  parsing/create_and_init_map2.c parsing/get_texture_data.c parsing/get_texture_data_utils.c
		  

UTILS = utils/ft_error.c utils/ft_close.c utils/ft_split_endl.c utils/ft_free.c utils/ft_count_nb_line.c \
		utils/ft_line_lowercase.c utils/ft_atoi_base.c utils/destroy_data.c utils/exit.c

INIT = init/player_init.c init/init_game.c init/init_img.c

3D = 3D/3D_render.c 3D/draw_window.c

SRCS = main.c $(RAYCASTING) $(INIT) $(MOVE) $(DRAW) $(3D) $(PARSING) $(UTILS)
SRCS := $(addprefix $(SRCS_PATH), $(SRCS))

OBJECT = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I $(INCS_PATH) -g3

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