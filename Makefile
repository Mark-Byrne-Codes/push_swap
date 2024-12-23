# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 09:42:15 by codespace         #+#    #+#              #
#    Updated: 2024/12/20 11:46:15 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

SRC_DIR = srcs
SRC_FILES = push_swap.c push_swap_utils.c init_stack.c init_stack_a.c init_stack_b.c \
            push_swap_error_check.c operations/swap.c operations/push.c  \
            operations/rev_rotate.c operations/rotate.c sort_stack.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
					@make -C ./libft

$(NAME): $(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
					@$(RM) $(OBJ)
					@make clean -C ./libft

fclean: clean
					@$(RM) $(NAME)
					@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
