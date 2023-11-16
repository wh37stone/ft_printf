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
SRC = ft_printf.c ft_specifier.c ft_putunbr_fd.c ft_puthex_fd.c ft_putaddr_fd.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	make fclean -C ./Libft
	ar rc $(NAME) $(OBJ)
$(LIBFT): ./Libft
	make -C ./Libft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
