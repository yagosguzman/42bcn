# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 19:05:57 by ysanchez          #+#    #+#              #
#    Updated: 2023/10/19 20:56:16 by ysanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
PRINTF = ft_printf

FLAGS = -Wall -Werror -Wextra
CC = gcc

SRC.SV = server.c
SRC.CL = client.c
SRC.UTILS = utils.c
OBJ.SV = $(SRC.SV:.c=.o)
OBJ.CL = $(SRC.CL:.c=.o)
OBJ.UTILS = $(SRC.UTILS:.c=.o)

all: $(OBJ.SV) $(OBJ.CL) $(OBJ.UTILS)
	@$(CC) $(FLAGS) $(SRC.SV) $(SRC.UTILS) -o $(SERVER)
	@$(CC) $(FLAGS) $(SRC.CL) $(SRC.UTILS) -o $(CLIENT)
	@echo "Server and Client ready to go!"

client: $(OBJ.CL) $(OBJ.UTILS)
	@$(CC) $(FLAGS) $(SRC.CL) $(SRC.UTILS) -o $(CLIENT)
	@echo "Client ready to go!"

server: $(OBJ.SV) $(OBJ.UTILS)
	@$(CC) $(FLAGS) $(SRC.SV) $(SRC.UTILS) -o $(SERVER)
	@echo "Server ready to go!"

clean:
	@rm -f $(OBJ.SV) $(OBJ.CL) $(OBJ.UTILS)
	@echo "Objects successfully removed"

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client successfully removed"

re: fclean all

.PHONY: make all client server clean fclean re