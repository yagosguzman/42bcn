# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 19:05:57 by ysanchez          #+#    #+#              #
#    Updated: 2023/10/26 19:31:34 by ysanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = so_long
EXEC_BONUS = so_long_bonus

CC = gcc
# TIENES PUESTO EL DEBUGGER EN FLAGS
FLAGS = -g -Wall -Werror -Wextra
RM = rm -f

HEADER = ./inc/solong.h
SRC = $(wildcard src/*.c)
SRC_BONUS = ./bonus/$(wildcard *.c)
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
DEPS = $(addsuffix .d, $(basename $(SRC)))
BONUSDEPS = $(addsuffix .d, $(basename $(SRC_BONUS)))

all: $(EXEC)

-include $(DEPS)
$(EXEC): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(SRC) -o $(EXEC)
	@make -C ./minilibx all
	@echo "Executable ready!"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

-include $(BONUS_DEPS)
bonus: $(OBJ_BONUS) $(HEADER)
	@$(CC) $(FLAGS) $(SRC_BONUS) -o $(EXEC_BONUS)
	@make -C ./minilibx all
	# @touch $@
	@echo "BONUS: Executable ready!"

clean:
	@make -C ./minilibx clean
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@$(RM) $(DEPS) $(BONUS_DEPS)
	@echo "Objects successfully removed"

fclean: clean
	@$(RM) $(EXEC) $(EXEC_BONUS)
	# @${RM} bonus
	@${RM} ${EXEC} ${EXEC_BONUS} libmlx.a
	@echo "Executable successfully removed"

re: fclean all

.PHONY: make all clean fclean re bonus