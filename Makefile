# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 20:15:35 by sbruen            #+#    #+#              #
#    Updated: 2019/03/24 18:57:13 by ksnow-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
CC = gcc
SRC_DIR = srcs/
LIBFT_DIR = libft/
OBJ_DIR = obj/

CHECKER_SRCS = conditions.c opers2.c algo.c help_algo.c help_algo2.c help_algo3.c help_algo4.c init.c opers.c valid.c vizu.c checker.c
PS_SRCS = conditions.c opers2.c algo.c help_algo.c help_algo2.c help_algo3.c help_algo4.c init.c opers.c valid.c vizu.c push_swap.c

CHECKER_OBJ = ${CHECKER_SRCS:c=o}
PS_OBJ = ${PS_SRCS:c=o}

all: $(CHECKER) $(PUSH_SWAP)

$(addprefix $(OBJ_DIR), %.o): $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -g `sdl2-config --cflags` -I libft/ -I include/ -c -o $@ $^

$(CHECKER): $(addprefix $(OBJ_DIR), $(CHECKER_OBJ))
	@make -C libft/
	@$(CC) $(addprefix $(OBJ_DIR), $(CHECKER_OBJ)) $(LIBFT_DIR)libft.a         \
								`sdl2-config --libs` -I libft/ -I include/ -o $(CHECKER)

$(PUSH_SWAP): $(addprefix $(OBJ_DIR), $(PS_OBJ))
	@$(CC) $(addprefix $(OBJ_DIR), $(PS_OBJ)) $(LIBFT_DIR)libft.a    \
		`sdl2-config --libs` -I libft/ -I include/ -o $(PUSH_SWAP)
	@echo "🖕 "

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(CHECKER)
	@echo "\n\033[31m$(CHECKER)   💀"
	@rm -f $(PUSH_SWAP)
	@echo "$(PUSH_SWAP) 💀\033[m"

re: fclean all
