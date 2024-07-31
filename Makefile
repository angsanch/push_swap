# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 18:29:24 by angsanch          #+#    #+#              #
#    Updated: 2024/07/30 16:13:07 by angsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

CFLAGS=-Wall -Werror -Wextra -g

C_FILES = src/main.c \
			src/tools/ps.c \
			src/tools/num.c \
			src/parsing/input.c \
			src/parsing/stack.c \
			src/logic/sort.c \
			src/logic/sorted.c \
			src/logic/radix.c \
			src/logic/generic.c \
			src/logic/simple.c \
			src/logic/insertion.c \
			src/logic/ksort.c \
			src/operations/run.c \
			src/operations/swap.c \
			src/operations/push.c \
			src/operations/rotate.c \
			src/operations/reverse_rotate.c \

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
