# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 15:31:37 by sbadr             #+#    #+#              #
#    Updated: 2023/02/22 16:43:33 by sbadr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = srcs
OBJ_DIR = objs
SRCS =	parsing.c flood_fill.c main.c move.c mlx_function.c ft_split.c ft_strncmp.c ft_strdup.c ft_putnbr_fd.c ft_itoa.c ft_putchar_fd.c ft_strlen.c ft_putstr_fd.c get_next_line.c get_next_line_utils.c
OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)
CC  = cc
CFLAGS = -Wall -Wextra -Werror
MLX =  -Imlx -lmlx -framework OpenGL -framework AppKit
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(MLX) $^ -o ${NAME}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c so_long.h
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
