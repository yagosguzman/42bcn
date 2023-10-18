# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 19:05:57 by ysanchez          #+#    #+#              #
#    Updated: 2023/10/18 19:59:04 by ysanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
PRINTF = ft_printf

FLAGS = -Wall -Werror -Wextra
CC = gcc
HEADER = minitalk.h

SRC.SV = server.c
SRC.CL = client.c
OBJ.SV = $(SRC.SV:.c=.o)
OBJ.CL = $(SRC.CL:.c=.o)

all: $(OBJ.SV) $(OBJ.CL) $(HEADER)
	@make -s -C $(PRINTF)
	@$(CC) $(FLAGS) $(SRC.SV) -o $(SERVER)
	@$(CC) $(FLAGS) $(SRC.CL) -o $(CLIENT)
	@echo "Server and Client ready to go!"

client: $(OBJ.CL) $(HEADER)
	@$(CC) $(FLAGS) $(SRC.CL) -o $(CLIENT)
	@echo "Client ready to go!"

server: $(OBJ.SV) $(HEADER)
	@$(CC) $(FLAGS) $(SRC.SV) -o $(SERVER)
	@echo "Server ready to go!"

clean:
	@make clean -s -C $(PRINTF)
	@rm -f $(OBJ.SV) $(OBJ.CL)
	@echo "Objects successfully removed"

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client successfully removed"

re: fclean all

.PHONY: make all client server clean fclean re Makefile