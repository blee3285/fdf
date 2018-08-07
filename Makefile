# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blee <blee@student.42.us.org>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/01 18:08:58 by blee              #+#    #+#              #
#    Updated: 2018/08/06 18:55:14 by blee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR = ./srcs
OBJ_DIR = ./objs
MLX_DIR = ./mlx
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a
LIB = -L ./libft -L ./mlx -lft -lmlx
FRAME = -framework OpenGL -framework Appkit

SRC_FILES = main.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(LIBFT):
	make -C ./libft

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -Wall -Wextra -Werror -c $< -o $@ -I ./includes

$(MLX):
	make -C ./mlx

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT) $(MLX)
	gcc -o $(NAME) $(OBJS) $(LIB) $(FRAME)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft
	make clean -C mlx

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: clean all
