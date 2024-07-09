# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 10:20:09 by pmorello          #+#    #+#              #
#    Updated: 2024/07/09 09:21:54 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = src/*.c operations/*.c utils/*.c 
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibrary
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS} -Llibft -lft -o ${NAME}

clean: 
	${MAKE} -C ./libft fclean
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re