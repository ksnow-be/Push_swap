# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 20:15:35 by sbruen            #+#    #+#              #
#    Updated: 2019/03/19 16:22:52 by ksnow-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isalpha.c	ft_memmove.c ft_strchr.c ft_strlen.c ft_strrchr.c \
	   ft_atoi.c ft_isascii.c ft_memchr.c ft_strcmp.c ft_strncat.c \
	   ft_strstr.c ft_bzero.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strcpy.c \
	   ft_strncmp.c ft_tolower.c ft_isprint.c ft_memcpy.c ft_strdup.c \
	   ft_strncpy.c ft_toupper.c ft_isalnum.c ft_memccpy.c ft_strcat.c \
	   ft_strlcat.c ft_strnstr.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	   ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	   ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	   ft_strmapi.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
	   ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	   ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_int_num.c ft_check_num.c \
	   ft_words_num.c ft_str_fill.c ft_del.c get_next_line.c
OBJ = $(SRCS:.c=.o) 
FLAGS = -Wall -Wextra -Werror
HEADER = libft.h

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRCS) -I $(HEADER)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
