# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 21:01:02 by tyuuki            #+#    #+#              #
#    Updated: 2021/12/11 21:22:03 by tyuuki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SRCS =		ft_itoa.c\
			ft_printf.c\
			func_for_func.c\
			functions.c\
		  
OBJ =		$(patsubst %.c,%.o,$(SRCS))

CC =		gcc

FLAGS =		-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) ft_printf.h
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
	
re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f  $(NAME)

.PHONY: all clean fclean re










