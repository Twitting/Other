# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twitting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 14:23:06 by twitting          #+#    #+#              #
#    Updated: 2018/12/24 15:24:54 by twitting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = ./fdf_src/fdf.c \
	  ./fdf_src/ft_pointmaker.c \
	  ./fdf_src/ft_printlines.c \
	  ./fdf_src/ft_putline.c \
	  ./fdf_src/ft_freepnt.c
SRC2 = ./libft/libft.a
OBJECTS = fdf.o \
		  ft_pointmaker.o \
		  ft_printlines.o \
		  ft_putline.o \
		  ft_freepnt.o
FLAGS = -Wall -Wextra -Werror
FLAGS2 = -ggdb -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	make re -C libft/
	gcc $(FLAGS) $(SRC) -c
	gcc $(FLAGS) $(FLAGS2) $(OBJECTS) $(SRC2) -o $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
