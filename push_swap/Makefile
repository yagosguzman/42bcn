# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 14:55:58 by ysanchez          #+#    #+#              #
#    Updated: 2023/08/31 21:16:36 by ysanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpushswap.a

SRC = push_swap.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

HEADER = push_swap.h

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

.PHONY: make clean all fclean re