# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 19:05:57 by ysanchez          #+#    #+#              #
#    Updated: 2023/10/23 13:52:29 by ysanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRC_SV = server.c
SRC_CL = client.c
SRC_SV_BONUS = server_bonus.c
SRC_CL_BONUS = client_bonus.c
SRC_UTILS = utils.c
OBJ_SV = $(SRC_SV:.c=.o)
OBJ_CL = $(SRC_CL:.c=.o)
OBJ_SV_BONUS = $(SRC_SV_BONUS:.c=.o)
OBJ_CL_BONUS = $(SRC_CL_BONUS:.c=.o)
OBJ_UTILS = $(SRC_UTILS:.c=.o)

CC = gcc
FLAGS = -Wall -Werror -Wextra

all: $(OBJ_SV) $(OBJ_CL) $(OBJ_UTILS)
	@$(CC) $(FLAGS) $(SRC_SV) $(SRC_UTILS) -o $(SERVER)
	@$(CC) $(FLAGS) $(SRC_CL) $(SRC_UTILS) -o $(CLIENT)
	@echo "Server and Client ready to go!"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

client: $(OBJ_CL) $(OBJ_UTILS)
	@$(CC) $(FLAGS) $(SRC_CL) $(SRC_UTILS) -o $(CLIENT)
	@echo "Client ready to go!"

server: $(OBJ_SV) $(OBJ_UTILS)
	@$(CC) $(FLAGS) $(SRC_SV) $(SRC_UTILS) -o $(SERVER)
	@echo "Server ready to go!"

bonus: $(OBJ_SV_BONUS) $(OBJ_CL_BONUS) $(OBJ_UTILS)
	@$(CC) $(FLAGS) $(SRC_SV_BONUS) $(SRC_UTILS) -o $(SERVER_BONUS)
	@$(CC) $(FLAGS) $(SRC_CL_BONUS) $(SRC_UTILS) -o $(CLIENT_BONUS)
	@echo "BONUS: Server and Client ready to go!"

clean:
	@rm -f $(OBJ_SV) $(OBJ_CL) $(OBJ_UTILS) $(OBJ_SV_BONUS) $(OBJ_CL_BONUS)
	@echo "Objects successfully removed"

fclean: clean
	@rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "Server and Client successfully removed"

re: fclean all

.PHONY: make all client server clean fclean re bonus