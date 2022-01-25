# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartine <omartine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 12:21:40 by omartine          #+#    #+#              #
#    Updated: 2022/01/25 18:36:20 by omartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = my_checker_bonus.a

SRCS = my_checker.c movements_bonus/push.c movements_bonus/reverse.c \
		movements_bonus/rotates.c movements_bonus/swaps.c sort_management_bonus/3_sort.c \
		sort_management_bonus/100_sort.c sort_management_bonus/500_sort.c split.c \
		sort_management_bonus/sort_utils.c sort_management_bonus/sort_management.c \
		to_be_free.c main_utils.c 42_Get_next_line/get_next_line.c \
		42_Get_next_line/get_next_line_utils.c my_checker_utils.c

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
