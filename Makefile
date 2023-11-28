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
SRC = ft_putstr.c ft_putnbr.c ft_putunbr.c ft_puthexa.c ft_specifier.c ft_printf.c
OBJ = $(SRC:.c=.o)
BONUS_SRC = bonus/ft_print_zero_bonus.c bonus/ft_putstr_bonus.c bonus/ft_putnbr_bonus.c \
			bonus/ft_putunbr_bonus.c bonus/ft_puthexa_bonus.c \
			bonus/ft_check_iterate_bonus.c bonus/ft_specifier_bonus.c \
			bonus/ft_printf_bonus.c
BONUS_OBJ = $(OBJ) $(BONUS_SRC:.c=.o)
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ)
$(LIBFT):
	make -C ./Libft
	make clean -C ./Libft

bonus: $(NAME) $(BONUS_OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(BONUS_OBJ)

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./Libft

re: fclean all
