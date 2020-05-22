# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 15:11:11 by wtorwold          #+#    #+#              #
#    Updated: 2019/12/06 21:23:38 by wtorwold         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf
SRC := colour.c\
	fdf.c\
	ft_mlx.c\
	handle.c\
	isometric.c\
	readmap.c\
	start_param.c\
	transformcoords.c\
	print_description.c\

LIBFT = libft/libft.a
MLX := minilibx_macos/libmlx.a
FLAGS := -Wall -Wextra -Werror
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	gcc $(OBJ) -o $(NAME) -L libft -L minilibx_macos -lft  -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	gcc $(FLAGS) -I minilibx_macos -I libft -o $@ -c $<


$(MLX):
	make -C minilibx_macos

$(LIBFT):
	make -C libft


clean:
	/bin/rm -f $(OBJ)
	make clean  -C minilibx_macos
	make fclean  -C libft

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
