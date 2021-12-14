# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 21:01:02 by tyuuki            #+#    #+#              #
#    Updated: 2021/12/12 17:19:30 by tyuuki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include $(wildcard *.d)

NAME =		libftprintf.a

SRCS =		ft_itoa.c\
			ft_printf.c\
			func_for_func.c\
			functions.c\
		  
OBJ =		$(patsubst %.c,%.o,$(SRCS))

CC =		gcc

FLAGS =		-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $?

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -MMD
	
re: fclean all

clean:
	rm -f $(OBJ) *.d

fclean: clean
	rm -f  $(NAME)

.PHONY: all clean fclean re










