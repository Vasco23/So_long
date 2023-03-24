# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 02:38:36 by vcacador          #+#    #+#              #
#    Updated: 2023/03/24 17:12:45 by vcacador         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_NAME = 	main.c							\
			get_next_line.c					\
			get_next_line_utils.c			\
			line_len.c						\
			makeground.c					\
			ft_strncmp.c					\
			get_maps.c						\
			map_checker2.c					\
			map_checker.c					\
			global_structs.c				\
			global_structs_2.c				\
			image_utils.c					\
			make_addr.c						\
			collision.c						\
			ft_itoa.c 						\
			bad_guys.c						\
			run.c							\
			utils.c							\
			bad_guys_walk.c					

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Imlx -g -fsanitize=address
MILIB  = -I /usr/X11/include -g -L /usr/X11/lib -l minilibx-linux -framework OpenGL -framework AppKit

MLX_LIB_DIR = mlx_linux/
MLX_INCLUDE = -I mlx_linux/

LMLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -fPIC
RM = rm -f

HEADER = so_long.h

FT_PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF_PATH = ./ft_printf

INC = -Iincludes -I/usr/include -Imlx_linux

SRC_PATH = ./src

OBJ_PATH = ./objects

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

all: $(NAME)


$(NAME) : $(FT_PRINTF) $(OBJS)
	make -s -C mlx_linux/
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(INC) $(LMLX_FLAGS) $(MLX_INCLUDE) -o $(NAME)

$(FT_PRINTF): $(shell make -C $(FT_PRINTF_PATH) -q)
	make -C$(FT_PRINTF_PATH)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(MLX_LIB)
	mkdir -p objects
	$(CC) -c $(CFLAGS) $(LMLX_FLAGS) $(INC) $(MLX_INCLUDE) $< -o $@


clean:
	make clean -C $(FT_PRINTF_PATH)
	rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C $(FT_PRINTF_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re