# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twitting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 14:23:06 by twitting          #+#    #+#              #
#    Updated: 2018/12/22 18:32:53 by twitting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
SRC = ./fdf_src/*.c
SRC2 = ./libft/libft.a
OBJECTS = ./*.o
FLAGS = -Wall -Wextra -Werror
FLAGS2 = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -c
	gcc $(FLAGS) $(FLAGS2) $(OBJECTS) $(SRC2) -o $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all



#-I /usr/local/include fdf.c ft_pointmaker.c ft_printlines.c ft_putline.c ./libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit#
