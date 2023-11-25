# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joandre- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 02:21:02 by joandre-          #+#    #+#              #
#    Updated: 2023/11/09 02:41:51 by joandre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = Libft/libft.a
SRC = ft_printf.c ft_putstr.c ft_putnbr.c ft_putunbr.c ft_puthexa.c \
	  ft_specifier.c ft_dot_specifier.c ft_print_zero.c ft_check_iterate.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ)
$(LIBFT):
	make -C ./Libft
	make clean -C ./Libft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./Libft

re: fclean all
