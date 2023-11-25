# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 15:11:42 by tmalless          #+#    #+#              #
#    Updated: 2023/11/25 18:31:10 by tmalless         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strcmp.c ft_strncpy.c

OBJECT = $(SRCS:.c=.o)

SRCSBONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJECTBONUS = $(SRCSBONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJECT)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

bonus : $(OBJECT) $(OBJECTBONUS)
	ar rc $(NAME) $(OBJECT) $(OBJECTBONUS)
	ranlib $(NAME)

clean : 
	rm -f $(OBJECT) $(OBJECTBONUS)

fclean : clean
	rm -f libft.a

re : fclean all
