# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 17:19:15 by tmalless          #+#    #+#              #
#    Updated: 2022/12/16 17:40:46 by tmalless         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils_str.c ft_printf_utils_nbr.c ft_printf_utils_hexa.c

OBJECT = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJECT)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

clean : 
	rm -f $(OBJECT) $(OBJECTBONUS)

fclean : clean
	rm -f libftprintf.a

re : fclean all

.PHONY: all clean fclean re
