# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 21:43:23 by gayoub            #+#    #+#              #
#    Updated: 2019/12/31 19:34:37 by gayoub           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OPRION = -c

INCLUDE = headers

LIBFT_HEADER = headers/libft.h

GNL_HEADER = headers/get_next_line.h

SRCS_CHAR = 	ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isxdigit.c\
				ft_isprint.c\
				ft_tolower.c\
				ft_toupper.c\

SRCS_LISTS =	ft_lstadd.c\
				ft_lstaddback.c\
				ft_lstdel.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstmap.c\
				ft_lstnew.c\

SRCS_MEMORY =	ft_bzero.c\
				ft_memalloc.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memdel.c\
				ft_memmove.c\
				ft_memset.c\

SRCS_NUMEBR =	ft_itoa.c\
				ft_itoa_base.c\
				ft_declen.c

SRCS_STRINGS =  ft_atoi.c\
				ft_putnbr.c\
				ft_strchr.c\
				ft_strequ.c\
				ft_strmap.c\
				ft_strnew.c\
				ft_strstr.c\
				ft_countwords.c\
				ft_putnbr_fd.c\
				ft_strclr.c\
				ft_striter.c\
				ft_strmapi.c\
				ft_strnstr.c\
				ft_strsub.c\
				ft_putchar.c\
				ft_putnstr.c\
				ft_strcmp.c\
				ft_striteri.c\
				ft_strncat.c\
				ft_strrchr.c\
				ft_strtrim.c\
				ft_putchar_fd.c\
				ft_putstr.c\
				ft_strcpy.c\
				ft_strjoin.c\
				ft_strncmp.c\
				ft_strrdup.c\
				get_next_line.c\
				ft_putendl.c\
				ft_putstr_fd.c\
				ft_strdel.c\
				ft_strlcat.c\
				ft_strncpy.c\
				ft_strsplit.c\
				ft_putendl_fd.c\
				ft_strcat.c\
				ft_strdup.c\
				ft_strlen.c\
				ft_strnequ.c\
				ft_strstartwith.c


OBJ = $(SRCS_CHAR:%.c=%.o) $(SRCS_LISTS:%.c=%.o) $(SRCS_MEMORY:%.c=%.o) $(SRCS_NUMEBR:%.c=%.o) $(SRCS_STRINGS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) is READY !"

%.o : ft_char/%.c $(LIBFT_HEADER)
	@gcc $(CFLAGS) -I $(INCLUDE) -o $@ -c $<
	@echo "Compiled $< successfully !"

%.o : ft_lists/%.c $(LIBFT_HEADER)
	@gcc $(CFLAGS) -I $(INCLUDE) -o $@ -c $<
	@echo "Compiled $< successfully !"

%.o : ft_memory/%.c $(LIBFT_HEADER)
	@gcc $(CFLAGS) -I $(INCLUDE) -o $@ -c $<
	@echo "Compiled $< successfully !"

%.o : ft_number/%.c $(LIBFT_HEADER)
	@gcc $(CFLAGS) -I $(INCLUDE) -o $@ -c $<
	@echo "Compiled $< successfully !"

%.o : ft_strings/%.c $(LIBFT_HEADER) $(GNL_HEADER)
	@gcc $(CFLAGS) -I $(INCLUDE) -o $@ -c $<
	@echo "Compiled $< successfully !"

clean:
	@/bin/rm -rf $(OBJ)
	@echo "Clean objects of LIBFT !"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "Clean $(NAME) !"

re: fclean all
