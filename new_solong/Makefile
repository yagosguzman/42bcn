# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 19:05:57 by ysanchez          #+#    #+#              #
#    Updated: 2023/11/08 23:06:15 by ysanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -f
HEADER = ./inc/solong.h
HEADER_BONUS = ./inc/solong_bonus.h
SRC = src/so_long.c src/open_map.c src/render_map.c src/utils.c src/utils2.c \
	  src/error_handler.c src/get_next_line.c src/get_next_line_utils.c \
	  src/backtracking.c src/checker_map.c src/ingame_utils.c \
	  src/player_controls.c
SRC_BONUS = src_b/so_long_bonus.c src_b/open_map_bonus.c src_b/render_map_bonus.c \
			src_b/utils_bonus.c src_b/utils2_bonus.c src_b/error_handler_bonus.c \
			src_b/get_next_line_bonus.c src_b/get_next_line_utils_bonus.c \
			src_b/backtracking_bonus.c src_b/checker_map_bonus.c \
			src_b/ingame_utils_bonus.c src_b/player_controls_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
DEPS = $(addsuffix .d, $(basename $(SRC)))
BONUSDEPS = $(addsuffix .d, $(basename $(SRC_BONUS)))\

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJ) $(HEADER)
	@make -C ./mlx all
	@$(CC) $(FLAGS) $(SRC) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Executable ready!"

%.o:%.c Makefile 
	@$(CC) $(FLAGS) -Imlx -c $< -o $@


bonus: $(NAME_BONUS)

-include $(BONUS_DEPS)
$(NAME_BONUS): $(OBJ_BONUS) $(HEADER_BONUS)
	@make -C ./mlx all
	@$(CC) $(FLAGS) $(SRC_BONUS) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	@echo "BONUS: Executable ready!"
	
%bonus.o:%bonus.c Makefile 
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	@make -C ./mlx clean
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@$(RM) $(DEPS) $(BONUS_DEPS)
	@echo "Objects and libraries successfully removed"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "Executable successfully removed"

re: fclean all

.PHONY: make all clean fclean re bonus