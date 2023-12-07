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
.SILENT:
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = Libft/libft.a
SRC = ft_printf.c route_specifier.c putstr.c putnbr.c putunbr.c puthexa.c
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)
$(LIBFT):
	make -s -C ./Libft
	make clean -s -C ./Libft

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	make fclean -s -C ./Libft

re: fclean all
