# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 15:58:56 by gayoub            #+#    #+#              #
#    Updated: 2019/12/31 20:14:59 by gayoub           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror

SRC =	srcs/main.c\
		srcs/display_menu.c\
		srcs/read_stock.c\
		srcs/display_shape.c\
		srcs/handle_bonus.c\
		srcs/handle_event.c\
		srcs/handle_errors.c\
		srcs/free.c

LIB_FT = libft/libft.a

OBJ = $(SRC:%c=%o)

all : $(NAME)

$(LIB_FT) : lib

lib:
	@make -C libft

$(NAME) : $(LIB_FT) $(OBJ) fdf.h
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_FT) -lmlx -framework OpenGL -framework AppKit
	@echo "$(NAME) is READY!"

%.o : %.c fdf.h
	@gcc $(CFLAGS) -o $@ -c $<
	@echo "Compiled "$<" successfully!"

clean :
	@make clean -C libft
	@/bin/rm -rf $(OBJ)
	@echo "Clean objects of folder fdf !"

fclean : clean
	@make fclean -C libft
	@/bin/rm $(NAME)
	@echo "Clean clean $(NAME) !"

re : fclean all
