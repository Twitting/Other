# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twitting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 14:23:06 by twitting          #+#    #+#              #
#    Updated: 2018/12/28 17:52:24 by twitting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = ./fdf_src/fdf.c \
	  ./fdf_src/ft_pointmaker.c \
	  ./fdf_src/ft_printlines.c \
	  ./fdf_src/ft_putline.c \
	  ./fdf_src/ft_freepnt.c \
	  ./fdf_src/ft_keyboard.c
SRC2 = ./libft/libft.a
OBJECTS = fdf.o \
		  ft_pointmaker.o \
		  ft_printlines.o \
		  ft_putline.o \
		  ft_freepnt.o \
		  ft_keyboard.o
FLAGS = -Wall -Wextra -Werror
FLAGS2 = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
FLAGS3 = /usr/local/lib/libmlx.a /usr/local/include/mlx.h -lXext -lX11 -lm

all: $(NAME)

linux:
	make re -C libft/
	sudo gcc $(FLAGS) $(SRC) $(SRC2) $(FLAGS3) -o $(NAME)

$(NAME):
	make re -C libft/
	gcc $(FLAGS) $(SRC) -c
	gcc $(FLAGS) $(FLAGS2) $(OBJECTS) $(SRC2) -o $(NAME)

clean:
	make clean -C libft/
	/bin/rm -f $(OBJECTS)

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)

re: fclean all
