# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jburet <jburet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 16:25:26 by jburet            #+#    #+#              #
#    Updated: 2014/02/12 12:32:02 by jburet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

LIB_DIR = ./lib/

LIB = cd $(LIB_DIR)

HEADER = -I./ -I$(LIB_DIR)includes/

MLX = /usr/X11/lib

X11 = -L/usr/X11/include/X11 -lX11

NAME = lem_in

LINK = -L$(LIB_DIR) -lft -L$(MLX) -lXext -lX11 -lmlx $(X11)

FIC_C = main.c \
		entry.c \
		get_next_line.c \
		init_frmlr.c \
		get_frmlr.c \
		test_lem.c \
		paths.c \
		lem_mlx.c \
		lst.c \

FIC_O = $(FIC_C:.c=.o)

all: $(NAME)

$(NAME):
	$(LIB); make
	gcc -c $(FIC_C) $(LINK) $(HEADER) $(FLAGS)
	gcc -o $(NAME) $(FIC_O) $(LINK) $(HEADER) $(FLAGS)

clean:
	$(LIB); make clean $@
	rm -f $(FIC_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
