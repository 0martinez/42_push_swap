# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartine <omartine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 16:02:43 by omartine          #+#    #+#              #
#    Updated: 2022/01/19 16:40:40 by omartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libpush_swap.a

SRCS = push_swap.c movements.c sort_management.c 500_sort_binary_operators.c \
		movements/push.c movements/reverse.c movements/rotates.c \
		movements/swaps.c to_be_free.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean bonus rebonus
