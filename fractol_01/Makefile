# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jomason <jomason@student.42.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/13 18:09:47 by jomason           #+#    #+#              #
#    Updated: 2026/05/05 12:55:20 by jomason          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= ./libft
MLX_DIR		= ./mlx

SRC_DIR		= src
INLCUDES	= -I. -I$(LIBFT_DIR) -I$(MLX_DIR)

SRCS_FILES	=	color.c atod.c check_valid_double.c hooks.c julia.c \
				main.c mandelbrot.c parse.c ship.c updates.c utils.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRCS_FILES))

OBJS		= $(SRCS:.c=.o)

LIBS		= -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INLCUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@if [ -d "$(MLX_DIR)" ]; then make -C $(MLX_DIR) clean 2>/dev/null || true; fi
	rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re