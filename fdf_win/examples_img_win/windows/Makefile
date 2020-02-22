# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 14:38:42 by chzabakh          #+#    #+#              #
#    Updated: 2019/10/27 14:16:22 by chzabakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

all: $(NAME)

$(NAME):
		@gcc -Wall -Wextra -Werror -o $(NAME) main.c \
		-L /usr/local/lib -lmlx -framework OpenGl -framework AppKit

clean:
		

fclean: clean
		@rm -f $(NAME)

re: fclean all
