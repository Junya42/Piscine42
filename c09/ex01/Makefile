# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aremiki <aremiki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 21:17:11 by aremiki           #+#    #+#              #
#    Updated: 2020/07/21 21:17:15 by aremiki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c

OBJ = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

INCLUDES = ./includes

.c.o: 
	gcc $(FLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: 
	fclean all

.PHONY: 
	all clean fclean re
