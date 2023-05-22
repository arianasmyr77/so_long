# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 13:51:55 by arforouz          #+#    #+#              #
#    Updated: 2023/05/22 13:51:06 by arforouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

HEADER = so_long.h

CC = gcc
DEBUG = -g3 -fsanitize=address
CFLAGS =  -Wall -Wextra -Werror
#windows MLX_FLAGS = -L ./minilibx -lmlx -lXext -lX11 -lm -lbsd#-framework OpenGL -framework AppKit -lmlx
MLX_FLAGS = -L ./minilibx -framework OpenGL -framework AppKit -lmlx
LIBFT = ./libft/libft.a
MLX = ./minilibx/libmlx.a
LIB = ./assets/so_long.h
SRC_PATH = ./src/

SRC =	main.c \
		path_validation.c \
		path_validation_helper.c \
		check_map.c \
		check_map_helper.c \
		key_hooks.c \
		print_map.c \
		read_map.c \
		print_steps.c \
		utils.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJS = $(SRCS:.c=.o)

all: make_libft make_minilibx $(NAME)

make_libft:
	@make all -C ./libft

make_minilibx:
	@make all -C ./minilibx

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(LIB) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
	@make clean -C ./minilibx

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C ./libft
	@make clean -C ./minilibx

re: fclean all

re_bonus: fclean

.PHONY: all clean fclean re