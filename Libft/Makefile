# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 18:50:20 by ysanchez          #+#    #+#              #
#    Updated: 2023/06/21 17:31:43 by ysanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_lib.c ft_lib2.c ft_strncmp.c ft_toupper.c ft_tolower.c ft_memset.c \
ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
ft_memchr.c ft_memcmp.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_strnstr.c\
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c ft_split.c \

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f *.o .bonus

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

bonus: .bonus

.bonus: $(OBJ) $(OBJ_BONUS)
		ar rc $(NAME) $(OBJ) $(OBJ_BONUS)
		touch .bonus
