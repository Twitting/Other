# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twitting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 14:23:06 by twitting          #+#    #+#              #
#    Updated: 2018/12/11 20:12:13 by twitting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ./fillit_src/ft_fillit.c\
	  ./fillit_src/ft_disp.c\
	  ./fillit_src/ft_digit.c\
	  ./fillit_src/ft_input.c\
	  ./fillit_src/ft_recur.c
OBJECTS = ft_fillit.o ft_disp.o ft_digit.o ft_input.o ft_recur.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -c
	gcc $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
