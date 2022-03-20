# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdefonte <cdefonte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/29 12:16:09 by cdefonte          #+#    #+#              #
#    Updated: 2022/03/19 18:38:03 by cdefonte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 2048

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/
LIBFT_DIR = libft/

SRC_LST =	main.c			\
			print_image.c	\
			rand_num.c		\
			mov_functions.c	\
			descendant_function.c \
			ascendant_function.c

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)

SRC = $(addprefix $(SRC_DIR), $(SRC_LST))
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
INC = $(INC_DIR)wongkarwai.h 

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: libft $(NAME)

$(NAME): $(INC) $(OBJ) $(LIBFT_DIR)libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft -lncurses

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC) $(LIBFT_DIR)libft.a
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

clean:
	$(MAKE) $@ -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean:
	$(MAKE) $@ -C $(LIBFT_DIR)
	$(RM) $(OBJ) $(NAME)

re: fclean all

libft:
	$(MAKE) -C $(LIBFT_DIR)

.PHONY: all clean fclean re libft
