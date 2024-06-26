# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 19:05:57 by ysanchez          #+#    #+#              #
#    Updated: 2024/04/27 14:26:15 by ysanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
NAME_BONUS = philo_bonus
CC = gcc
FLAGS = -Wall -Werror -Wextra -fsanitize=address #-fsanitize=thread
RM = rm -f
HEADER = philo.h
HEADER_BONUS = philo_bonus.h
SRC = main.c error_handler.c check_arg.c utils.c data_init.c instructions.c \
		get_set_mutex.c sync_utils.c dining.c
SRC_BONUS = philo_bonus/
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
DEPS = $(addsuffix .d, $(basename $(SRC)))
BONUSDEPS = $(addsuffix .d, $(basename $(SRC_BONUS)))\

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "Executable ready!"

%.o:%.c Makefile 
	@$(CC) $(FLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

-include $(BONUS_DEPS)
$(NAME_BONUS): $(OBJ_BONUS) $(HEADER_BONUS)
	@$(CC) $(FLAGS) $(SRC_BONUS) -o $(NAME_BONUS)
	@echo "BONUS: Executable ready!"
	
%bonus.o:%bonus.c Makefile 
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@$(RM) $(DEPS) $(BONUS_DEPS)
	@echo "Objects and libraries successfully removed"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "Executable successfully removed"

re: fclean all

.PHONY: make all clean fclean re bonus