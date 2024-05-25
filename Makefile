# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 10:20:09 by pmorello          #+#    #+#              #
#    Updated: 2024/05/22 18:42:42 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS =  $(wildcard libft/*.c operations/*.c src/*.c utils/*.c)
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibrary
RM = rm -rf

all: ${NAME} 

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re