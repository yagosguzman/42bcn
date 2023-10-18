# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 16:22:53 by ysanchez          #+#    #+#              #
#    Updated: 2023/10/17 18:17:38 by ysanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c essentials.c auxfunctions.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
		ar rc $(NAME) $(OBJ)

%.o: %.c
		gcc $(FLAGS) -c -o $@ $<

clean:
		/bin/rm -f *.o

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
