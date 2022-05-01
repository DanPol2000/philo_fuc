# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chorse <chorse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 14:31:42 by chorse            #+#    #+#              #
#    Updated: 2022/05/01 19:41:07 by chorse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra -MMD -fsanitize=address -g

INC = philo.h

SRC	   = main.c usage.c init.c monitoring.c live.c\

OBJ = $(patsubst %.c,%.o,$(SRC))

D_OBJ = $(patsubst %.c,%.d,$(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(INC)
	gcc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(D_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
