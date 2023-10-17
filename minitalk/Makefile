# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 19:05:57 by ysanchez          #+#    #+#              #
#    Updated: 2023/10/17 17:21:46 by ysanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
PRINTF = ft_printf

FLAGS = -Wall -Werror -Wextra

CC = gcc

SRC.SV = server.c
SRC.CL = client.c

all: 
	@make -s -C $(PRINTF)
	@$(CC) $(FLAGS) $(SRC.SV) -o $(SERVER)
	@$(CC) $(FLAGS) $(SRC.CL) -o $(CLIENT)
	@echo "Server and Client ready to go!"

clean:
	@make clean -s -C $(PRINTF)
	@make clean rm -f *.o
	@echo "Objects successfully removed"

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client successfully removed"

re: fclean all

.PHONY: make clean all fclean re Makefile