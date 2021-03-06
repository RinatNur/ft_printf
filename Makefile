# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheat <jheat@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/26 12:02:44 by jheat             #+#    #+#              #
#    Updated: 2020/07/28 16:16:18 by jheat            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST  =	ft_parser.c ft_print_int.c ft_print_pointer.c ft_printf.c libft.c\
		ft_print_unsigned.c ft_print_xx.c ft_print_char_per.c ft_print_string.c

OBJ = $(patsubst %.c,%.o,$(LIST))

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $? 
		ranlib $(NAME)

%.o: %.c $(HEADER)
		gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

