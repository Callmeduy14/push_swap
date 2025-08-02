# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 00:00:00 by you               #+#    #+#              #
#    Updated: 2025/08/02 01:24:59 by yyudi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iincludes
RM			= rm -rf

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= main.c \
			  parsing.c \
			  operations/push.c \
			  operations/swap.c \
			  operations/rotate.c \
			  operations/reverse_rotate.c \
			  sorting/small_sort.c \
			  sorting/large_sort.c \
			  sorting/utils.c \
			  utils/stack_utils.c \
			  utils/math_utils.c\
			  utils/chunk_utils.c

OBJS		= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

clean:
			$(RM) $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
