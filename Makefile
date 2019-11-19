# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 15:58:56 by gayoub            #+#    #+#              #
#    Updated: 2019/11/18 21:47:29 by gayoub           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror -g

SRC =	main.c\
		display_home_win.c\
		read_stock.c\
		handle_event.c\
		handle_errors.c\
		display_shape.c

LIB_FT = libft/libft.a

OBJ = $(SRC:%c=%o)

all : $(NAME)

$(LIB_FT) : lib

lib:
	make -C libft

$(NAME) : $(LIB_FT) $(OBJ) fdf.h
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_FT) -lmlx -framework OpenGL -framework AppKit

%.o : %.c fdf.h
	gcc $(CFLAGS) -o $@ -c $<

clean :
	@make clean -C libft
	@/bin/rm -rf $(OBJ)

fclean : clean
	@make fclean -C libft
	@/bin/rm -rf $(NAME)

re : fclean all
