# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 18:50:20 by ysanchez          #+#    #+#              #
#    Updated: 2023/05/15 20:39:51 by ysanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_lib.c ft_lib2.c ft_strncmp.c ft_toupper.c ft_tolower.c ft_memset.c \
ft_memcpy.c ft_memmove.c ft_memchr.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

HEADER = libft.h

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
