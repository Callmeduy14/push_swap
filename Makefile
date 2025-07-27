# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/27 13:06:46 by yyudi             #+#    #+#              #
#    Updated: 2025/07/27 13:24:30 by yyudi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/main.c \
		src/operations/push.c \
		src/operations/swap.c \
		src/operations/rotate.c \
		src/operations/reverse_rotate.c \
		src/sort/small_sort.c \
		src/sort/large_sort.c \
		src/utils/stack_utils.c \
		src/utils/math_utils.c \
		src/parse.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
