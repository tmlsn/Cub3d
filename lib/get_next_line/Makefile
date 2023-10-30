# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 17:19:15 by tmalless          #+#    #+#              #
#    Updated: 2022/12/16 12:37:39 by tmalless         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

SRCS = get_next_line.c get_next_line_utils.c 

OBJECT = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJECT)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

clean : 
	rm -f $(OBJECT) $(OBJECTBONUS)

fclean : clean
	rm -f gnl.a

re : fclean all

.PHONY: all clean fclean re
