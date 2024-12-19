# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 09:42:15 by codespace         #+#    #+#              #
#    Updated: 2024/12/19 06:24:57 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

SRC_DIR = srcs
SRC_FILES = push_swap.c push_swap_utils.c init_stack.c init_stack_a.c init_stack_b.c \
            push_swap_error_check.c operations/swap.c operations/push.c operations/sort_three.c \
            operations/rev_rotate.c operations/sort_stack.c operations/rotate.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
    $(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
    make -C libft

clean:
    rm -f $(OBJ)
    make -C libft clean

fclean: clean
    rm -f $(NAME)
    make -C libft fclean

re: fclean all

.PHONY: all clean fclean re