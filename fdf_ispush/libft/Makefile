# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 21:43:23 by gayoub            #+#    #+#              #
#    Updated: 2019/12/31 20:34:06 by gayoub           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OPRION = -c

INCLUDE = headers

LIBFT_HEADER = headers/libft.h

GNL_HEADER = headers/get_next_line.h

SRCS_CHAR = 	ft_char/ft_isalnum.c\
				ft_char/ft_isalpha.c\
				ft_char/ft_isascii.c\
				ft_char/ft_isdigit.c\
				ft_char/ft_isxdigit.c\
				ft_char/ft_isprint.c\
				ft_char/ft_tolower.c\
				ft_char/ft_toupper.c\

SRCS_LISTS =	ft_lists/ft_lstadd.c\
				ft_lists/ft_lstaddback.c\
				ft_lists/ft_lstdel.c\
				ft_lists/ft_lstdelone.c\
				ft_lists/ft_lstiter.c\
				ft_lists/ft_lstmap.c\
				ft_lists/ft_lstnew.c\

SRCS_MEMORY =	ft_memory/ft_bzero.c\
				ft_memory/ft_memalloc.c\
				ft_memory/ft_memccpy.c\
				ft_memory/ft_memchr.c\
				ft_memory/ft_memcmp.c\
				ft_memory/ft_memcpy.c\
				ft_memory/ft_memdel.c\
				ft_memory/ft_memmove.c\
				ft_memory/ft_memset.c\

SRCS_NUMEBR =	ft_number/ft_itoa.c\
				ft_number/ft_itoa_base.c\
				ft_number/ft_declen.c

SRCS_STRINGS =  ft_strings/ft_atoi.c\
				ft_strings/ft_putnbr.c\
				ft_strings/ft_strchr.c\
				ft_strings/ft_strequ.c\
				ft_strings/ft_strmap.c\
				ft_strings/ft_strnew.c\
				ft_strings/ft_strstr.c\
				ft_strings/ft_countwords.c\
				ft_strings/ft_putnbr_fd.c\
				ft_strings/ft_strclr.c\
				ft_strings/ft_striter.c\
				ft_strings/ft_strmapi.c\
				ft_strings/ft_strnstr.c\
				ft_strings/ft_strsub.c\
				ft_strings/ft_putchar.c\
				ft_strings/ft_putnstr.c\
				ft_strings/ft_strcmp.c\
				ft_strings/ft_striteri.c\
				ft_strings/ft_strncat.c\
				ft_strings/ft_strrchr.c\
				ft_strings/ft_strtrim.c\
				ft_strings/ft_putchar_fd.c\
				ft_strings/ft_putstr.c\
				ft_strings/ft_strcpy.c\
				ft_strings/ft_strjoin.c\
				ft_strings/ft_strncmp.c\
				ft_strings/ft_strrdup.c\
				ft_strings/get_next_line.c\
				ft_strings/ft_putendl.c\
				ft_strings/ft_putstr_fd.c\
				ft_strings/ft_strdel.c\
				ft_strings/ft_strlcat.c\
				ft_strings/ft_strncpy.c\
				ft_strings/ft_strsplit.c\
				ft_strings/ft_putendl_fd.c\
				ft_strings/ft_strcat.c\
				ft_strings/ft_strdup.c\
				ft_strings/ft_strlen.c\
				ft_strings/ft_strnequ.c\
				ft_strings/ft_strstartwith.c


OBJ = $(SRCS_CHAR:%.c=%.o) $(SRCS_LISTS:%.c=%.o) $(SRCS_MEMORY:%.c=%.o) $(SRCS_NUMEBR:%.c=%.o) $(SRCS_STRINGS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) is READY !"

%.o : %.c $(LIBFT_HEADER)
	@gcc $(CFLAGS) -I $(INCLUDE) -o $@ -c $<
	@echo "Compiled $< successfully !"

%.o : %.c $(LIBFT_HEADER)
	@gcc $(CFLAGS) -I $(INCLUDE) -o $@ -c $<
	@echo "Compiled $< successfully !"

%.o : %.c $(LIBFT_HEADER)
	@gcc $(CFLAGS) -I $(INCLUDE) -o $@ -c $<
	@echo "Compiled $< successfully !"

%.o : %.c $(LIBFT_HEADER)
	@gcc $(CFLAGS) -I $(INCLUDE) -o $@ -c $<
	@echo "Compiled $< successfully !"

%.o : %.c $(LIBFT_HEADER) $(GNL_HEADER)
	@gcc $(CFLAGS) -I $(INCLUDE) -o $@ -c $<
	@echo "Compiled $< successfully !"

clean:
	@/bin/rm -rf $(OBJ)
	@echo "Clean objects of LIBFT !"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "Clean $(NAME) !"

re: fclean all
