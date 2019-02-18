# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twitting <twitting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 14:23:06 by twitting          #+#    #+#              #
#    Updated: 2019/02/18 17:01:36 by twitting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
SRC = ./wolf_src/getintmap.c \
	  ./wolf_src/main.c \
	  ./wolf_src/raycaster.c \
	  ./wolf_src/userinput.c
SRC2 = ./libft/libft.a
OBJECTS = getintmap.o \
		  main.o \
		  raycaster.o \
		  userinput.o
FLAGS = -Wall -Wextra -Werror
FLAGS2 = -Iincludes/ -I /usr/local/include -L /usr/local/lib -lmlx -lpthread -framework OpenGL -framework AppKit
FLAGS_LINUX = -I ./includes_linux/ /usr/X11/lib/libmlx.a  -lXext -lX11 -lm -lpthread

all: $(NAME)

linux:
	make re -C libft/
	sudo gcc $(FLAGS) $(SRC) $(SRC2) $(FLAGS_LINUX) -o $(NAME)

$(NAME):
	make re -C libft/
	gcc $(FLAGS) $(SRC) -Iincludes/ -c
	gcc -g $(FLAGS) $(FLAGS2) $(OBJECTS) $(SRC2) -o $(NAME)

clean:
	make clean -C libft/
	/bin/rm -f $(OBJECTS)

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)

re: fclean all

re_linux: fclean linux
