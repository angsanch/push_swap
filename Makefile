# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 18:29:24 by angsanch          #+#    #+#              #
#    Updated: 2024/06/20 07:01:04 by angsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

CFLAGS=-Wall -Werror -Wextra

C_FILES = src/main.c \
			src/tools/ps.c \
			src/tools/num.c \
			src/parsing/input.c \
			src/parsing/stack.c \
			src/logic/sort.c \

O_FILES = $(C_FILES:.c=.o)

LIB = libft/libft.a

NAME=push_swap

$(NAME): $(LIB) $(O_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(O_FILES) $(LIB)

all: $(NAME)

clean:
	make -C libft clean
	rm -f $(O_FILES) test_$(NAME)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

$(LIB):
	make -C libft

re: fclean all

.PHONY: all clean fclean re
