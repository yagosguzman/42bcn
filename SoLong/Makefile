# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 19:05:57 by ysanchez          #+#    #+#              #
#    Updated: 2023/11/08 20:24:44 by ysanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
FLAGS = -Wall -Werror -Wextra #-g -fsanitize=address
RM = rm -f

HEADER = ./inc/solong.h
SRC = $(wildcard src/*.c)
SRC_BONUS = ./bonus/$(wildcard *.c)
OBJ = $(SRC:.c=.o)
DEPS = $(addsuffix .d, $(basename $(SRC)))

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJ) $(HEADER)
	@make -C ./mlx all
	@$(CC) $(FLAGS) $(SRC) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Executable ready!"

%.o: %.c
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	@make -C ./mlx clean
	@$(RM) $(OBJ)
	@$(RM) $(DEPS)
	@echo "Objects and libraries successfully removed"

fclean: clean
	@$(RM) $(NAME)
	@${RM} ${NAME}
	@echo "Executable successfully removed"

re: fclean all

.PHONY: make all clean fclean re