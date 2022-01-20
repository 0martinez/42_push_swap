# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartine <omartine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 16:02:43 by omartine          #+#    #+#              #
#    Updated: 2022/01/20 13:46:56 by omartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libpush_swap.a

SRCS = push_swap.c movements/push.c movements/reverse.c movements/rotates.c \
		movements/swaps.c sort_management/3_sort.c sort_management/100_sort.c \
		sort_management/500_sort.c sort_management/sort_utils.c \
		sort_management/sort_management.c push_swap.c to_be_free.c main_utils.c

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
