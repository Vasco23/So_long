# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 02:38:36 by vcacador          #+#    #+#              #
#    Updated: 2022/11/26 20:03:40 by vcacador         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Imlx -g
MILIB  = -I /usr/X11/include -g -L /usr/X11/lib -l minilibx-linux -framework OpenGL -framework AppKit

MLX_LIB_DIR = mlx_linux/
MLX_INCLUDE = -I mlx_linux/

LMLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -fPIC
RM = rm -f

$(VERBOSE).SILENT:

HEADER = so_long.h

FT_PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF_PATH = ./ft_printf

INC = -I ./includes

SRC_PATH = ./src

OBJ_PATH = ./objects

SRC_NAME = 	main.c							\
			get_next_line.c					\
			get_next_line_utils.c			\
			line_len.c						\
			makeground.c					\
			ft_strncmp.c					\
			get_maps.c						\
			map_checker2.c					\
			map_checker.c

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

all: $(NAME)


$(NAME) : $(FT_PRINTF) $(OBJS)
	make -s -C mlx_linux/
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(INC) $(LMLX_FLAGS) $(MLX_INCLUDE) -o $(NAME)
	@echo "\033[1;36m[COMPILED]\033[0m"

$(FT_PRINTF): $(shell make -C $(FT_PRINTF_PATH) -q libftprintf.a || echo force)
	make -C$(FT_PRINTF_PATH)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(MLX_LIB)
	mkdir -p objects
	$(CC) -c $(CFLAGS) $(LMLX_FLAGS) $(INCLUDES) $(MLX_INCLUDE) $< -o $@

norminette:
	clear
	norminette | egrep -B1 'Error|Warning' | sed ''/Error/s//$(printf "\033[31m\033[4mError\033[0m")/'' | sed ''/Warning/s//$(printf "\033[33m\033[4mWarning\033[0m")/''

clean:
	make clean -C $(FT_PRINTF_PATH)
	rm -rf $(OBJ_PATH)
	echo "\033[33mall $(NAME).o files are removed\033[0m"

fclean: clean
	make fclean -C $(FT_PRINTF_PATH)
	rm -f $(NAME)
	echo "\033[31m$(NAME) is deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re force norminette