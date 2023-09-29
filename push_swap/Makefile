# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 14:55:58 by ysanchez          #+#    #+#              #
#    Updated: 2023/09/29 20:01:43 by ysanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c lists_tools.c checks.c create_list.c \
	calculators.c move_push_swap.c move_rotate.c \
	move_rev_rotate.c algorithm.c utils.c utils2.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
		cc ${SRC} -o ${NAME}

%.o: %.c
		cc $(FLAGS) -c $< -o $@

clean:
		/bin/rm -f *.o

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: make clean all fclean re