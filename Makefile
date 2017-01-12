# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 15:09:27 by mlubisi           #+#    #+#              #
#    Updated: 2017/01/12 16:07:13 by mlubisi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

FLAGS = -Wall -Werror -Wextra

HEADERS = -I include

SRCS = src/main.c src/ft_hook_.c src/ft_interact_.c \
       src/ft_rm_.c src/ft_events.c src/ft_print_.c \
	   src/ft_strman.c src/ft_strs_.c src/ft_invoke_.c \
	   src/ft_tools_.c

LIB = -ltermcap

all:
	@gcc $(FLAGS) $(SRCS) $(HEADERS) $(LIB) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all
