# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgraczyk <kgraczyk@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 23:08:27 by kgraczyk          #+#    #+#              #
#    Updated: 2024/05/05 11:25:05 by kgraczyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include/
RM = rm -rf
NAME = libftprintf.a

SRCS = ft_printf.c srcs/print_hex.c srcs/print_int.c srcs/print_point.c srcs/print_string.c srcs/print_unsigned.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re

.SILENT:
